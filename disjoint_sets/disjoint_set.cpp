#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
//普通版并查集,用一个数组来储存当前节点的父节点
int f[MAXN];
//初始时，所有的节点的父节点都是自己
int n;
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
} //初始化集合，每个集合一开始都只有一个节点

int find(int a)
{
    if (f[a] == a)
        return a;
    else
    {
        return find(f[a]);
    }
} //递归
//非递归
int find1(int a)
{
    if (f[a] == a)
        return a;
    else
    {
        while (f[a] != a)
            a = f[a];
        return a;
    }
}
//考虑路径压缩
int find2(int a)
{
    if (a == f[a])
        return a;
    else
    {
        return a = find2(f[a]); //每次向上的过程中可以同时更新每一个经过的父节点，从而将路径压缩
    }
}
void merge(int a, int b)
{
    int root1 = find2(a);
    int root2 = find2(b);
    if (root1 != root2)
    {
        f[root1] = root2;
    }
} //合并
