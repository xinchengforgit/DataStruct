//中序遍历的递归实现与非递归实现
#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
typedef struct
{
    int val;
    bitree ls;
    bitree rs;
} binode, *bitree;
stack<bitree> s;

void build(bitree &root)
{
    int val;
    cin >> val;
    if (val == -1)
        root = NULL;
    else
    {
        root = (bitree)malloc(sizeof(binode));
        root->val = val;
        build(root->ls);
        build(root->rs);
    }
}

//递归实现
void in(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        in(root->ls);
        printf("%d ", root->val);
        in(root->rs);
    }
}

//迭代实现
void in(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        while (!s.empty() || root != NULL)
        {
            if (root != NULL)
            {
                s.push(root);
                root = root->ls;
            }
            else
            {
                root = s.top();
                s.pop();
                printf("%d ", root->val);
                root = root->rs;
            }
        }
    }
}