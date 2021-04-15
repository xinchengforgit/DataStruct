#include <cstdio>
#include <algorithm>
typedef struct node
{
    int val;
    node *ls;
    node *rs;
} binode;
typedef binode *bitree;
void create(bitree &root)
{
    int val;
    scanf("%d", &val);
    if (val == -1)
    {
        root = NULL;
        return;
    }
    else
    {
        bitree ptr = (bitree)malloc(sizeof(binode));
        ptr->val = val;
        root = ptr;
        create(root->ls);
        create(root->rs);
    }
}
void morris(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        bitree cur, mostright;
        cur = root;
        mostright = NULL;
        while (cur != NULL)
        {
            mostright = cur->ls;
            //有左树的情况下
            if (mostright != NULL)
            {
                while (mostright->rs != NULL && mostright->rs != cur)
                {
                    mostright = mostright->rs;
                }
                if (mostright->rs == NULL)
                {
                    mostright->rs = cur;
                    cur = cur->ls;
                    continue;
                }
                else
                {
                    mostright->rs = NULL;
                }
            }
            cur = cur->rs;
        }
    }
}
//具体原理实现如下,首先对于一个有左子树的节点，必然会经过两次该节点，当第二次经过该节点时，即表示左子树已经遍历完，故而对于前序和中序遍历
//只需要修改打印的地方即可
//前序打印如下
void morris1(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        bitree cur = root, mostright = NULL;
        while (cur != NULL)
        {
            mostright = cur->ls;
            if (mostright != NULL)
            {
                while (mostright->rs != NULL && mostright->rs != cur)
                {
                    mostright = mostright->rs;
                }
                if (mostright->rs == NULL)
                {
                    mostright->rs = cur;
                    printf("%d   ", cur->val);
                    cur = cur->ls;
                    continue;
                }
                else
                {
                    mostright->rs = NULL;
                    cur = cur->rs;
                    continue;
                }
            }
            else
            {
                printf("%d   ", cur->val);
                cur = cur->rs;
            }
        }
    }
}
//中序遍历
void morrris2(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        bitree cur = root, mostright = NULL;
        while (cur != NULL)
        {
            mostright = cur->ls;
            if (mostright != NULL)
            {
                while (mostright->rs != NULL && mostright->rs != cur)
                    mostright = mostright->rs;
                if (mostright->rs == NULL)
                {
                    mostright->rs = cur;
                    cur = cur->ls;
                    continue;
                }
                else
                {
                    printf("%d    ", cur->val);
                    mostright->rs = NULL;
                    cur = cur->rs;
                }
            }
            else
            {
                printf("%d     ", cur->val);
                cur = cur->rs;
            }
        }
    }
}
void morris3(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        bitree cur = root, mostright;
        while (cur != NULL)
        {
            mostright = cur->ls;
            if (mostright != NULL)
            {
                while (mostright->rs != NULL && mostright->rs != cur)
                    mostright = mostright->rs;
                if (mostright->rs == NULL)
                {
                    mostright->rs = cur;
                    cur = cur->ls;
                    continue;
                }
                else
                {
                    /* 将右边界逆序打印*/
                    cur = cur->rs;
                    mostright->rs = NULL;
                }
            }
            else
            {
                cur = cur->rs;
            }
        }
    }
}
int main()
{
    bitree root;
    create(root);
    morris1(root);
    printf("\n");
    morrris2(root);
    return 0;
}