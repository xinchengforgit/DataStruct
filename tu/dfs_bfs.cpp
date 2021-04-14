#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 10000
int n, m;
struct Linknode
{
    int vex;
    Linknode *next;
};
struct node
{
    int data;
    Linknode *head;
} nodes[MAXN];
bool visit[MAXN] = {false};
queue<Linknode *> q;
void create()
{
    for (int i = 1; i <= n; i++)
        nodes[i].head = NULL;
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        Linknode *ptr = (Linknode *)malloc(sizeof(Linknode));
        ptr->vex = to;
        ptr->next = nodes[from].head;
        nodes[from].head = ptr;
    }
}
void dfs(int n)
{
    visit[n] = true;
    Linknode *now = nodes[n].head;

    printf("%d->", n);
    while (now != NULL)
    {
        int vex = now->vex;
        if (visit[vex] == false)
            dfs(vex);
        now = now->next;
    }
}
void bfs(int n)
{
    visit[n] = true;
    q.push(nodes[n].head);
    printf("%d", n);
    while (!q.empty())
    {
        Linknode *ptr = q.front();
        q.pop();
        while (ptr != NULL)
        {
            if (visit[ptr->vex] == false)
            {
                printf("->%d", ptr->vex);
                q.push(ptr->next);
                visit[ptr->vex] = true;
            }

            ptr = ptr->next;
        }
    }
}

int main()
{
    cin >> n >> m;
    create();
    bfs(1);
    printf("\n");
    memset(visit, false, sizeof(visit));
    dfs(1);
    return 0;
}
