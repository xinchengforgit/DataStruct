//先序遍历的递归实现与非递归实现
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
void first(bitree &root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    first(root->ls);
    first(root->rs);
}

//非递归实现
void first2(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            if (root->rs != NULL)
                s.push(root->rs);
            if (root->ls != NULL)
                s.push(root->ls);
            printf("%d ", root->val);
        }
    }
} //先序遍历的非递归实现