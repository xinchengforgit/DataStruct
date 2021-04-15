#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
int f[MAXN];
int n, m; //n表示节点个数
int tot;
struct edge
{
    int from;
    int to;
    int w;
} e[MAXN];

void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
}
int find(int x)
{
    if (f[x] == x)
        return;
    else
        return x = find(f[x]);
}
void merge(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    if (root1 != root2)
    {
        f[root1] = root2;
    }
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void kruskal()
{
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (find(e[i].from) != find(e[i].to))
        {
            merge(e[i].from, e[i].to); //没有在一起，则合并
            tot += e[i].w;
        }
    }
}
int main()
{
    cin >> n >> m;
}
