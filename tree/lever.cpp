#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node
{
    int val;
    node *ls;
    node *rs;
} binode, *bitree;
queue<bitree> q;
void lever(bitree &root)
{
    if (root == NULL)
        return;
    else
    {
        q.push(root);
        while (!q.empty())
        {
            bitree temp = q.front();
            printf("%d ", temp->val);
            q.pop();
            if (temp->ls != NULL)
                q.push(temp->ls);
            if (temp->rs != NULL)
                q.push(temp->rs);
        }
    }
} //层次遍历(即bfs)
