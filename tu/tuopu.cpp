#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
#define MAXN 1000 + 5
int n, m;
int a[MAXN][MAXN];
int deg[MAXN];
int mark[MAXN];
//邻接矩阵建有向图
void create()
{
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        a[from][to] = 1;
        deg[to]++; //to的入度加1
    }
}
//基于邻接矩阵
void tsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
        {
            q.push(i);
            mark[i] = 1;
        }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        printf("%d ", p);
        for (int i = 1; i <= n; i++)
            if (a[p][i] == 1)
                deg[i]--;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0 && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
    }
}
//基于邻接表的话
struct Linknode
{
    int vex;
    Linknode *nex;
};
struct node
{
    int data;
    Linknode *head;
} nodes[MAXN];
void create2()
{
    for (int i = 1; i <= n; i++)
        nodes[i].head = NULL;
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        Linknode *ptr = (Linknode *)malloc(sizeof(Linknode));
        ptr->vex = to;
        ptr->nex = nodes[from].head;
        nodes[from].head = ptr;
        deg[to]++; //顺带处理to的入度
    }
}
void tsort2()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
        {
            q.push(i);
            mark[i] = 1;
        }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        printf("%d  ", temp);
        Linknode *ptr = nodes[temp].head;
        while (ptr != NULL)
        {
            if (--deg[ptr->vex] == 0)
            {
                mark[ptr->vex] = 1;
                q.push(ptr->vex);
            }
            ptr = ptr->nex;
        }
    }
}
int main()
{
    cin >> n >> m;
    create2();

    tsort2();

    return 0;
}