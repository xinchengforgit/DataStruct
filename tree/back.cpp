#include <iostream>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
    int val;
    bitree ls;
    bitree rs;
} binode, *bitree;
stack<bitree> s;

void back(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        back(root->ls);
        back(root->rs);
        printf("%d ", root->val);
    }
}
void back1(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        s.push(root);
        stack<int> vals;
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            if (root->ls != NULL)
                s.push(root->ls);
            if (root->rs != NULL)
                s.push(root->rs);
            vals.push(root->val);
        }
        while (!vals.empty())
        {
            int temp = vals.top();
            vals.pop();
            printf("%d ", temp);
        }
    }
}