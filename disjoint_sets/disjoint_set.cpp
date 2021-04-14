#include <cstdio>
#include <iostream>
using namespace std;
//普通版并查集,用一个数组来储存当前节点的父节点
int f[10000];
//初始时，所有的节点的父节点都是自己
int n, m; //n表示节点个数
void init()
{
    for (int i = 1; i <= n; i++)
        f[i] = i;
} //初始化集合，每个集合一开始都只有一个节点
void merge(int a, int b)
{
    f[a] = b;
}
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
int find3(int a)
{
    if (a == f[a])
        return a;
    else
    {
        return a = find(f[a]); //每次向上的过程中可以同时更新每一个经过的父节点，从而将路径压缩
    }
}
