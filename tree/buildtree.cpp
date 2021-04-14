#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define maxn 1000000
using namespace std;
struct egde
{
    int from;
    int to;
} e[maxn];
int first[maxn]; //储存每一个节点的首条边(一开始初始化为0)
int nex[maxn];   //储存第i条边下一条边的下标
int tot;         //储存边的总数
//一般的树的建法(采用邻接表法)
void add(int s, int t)
{
    e[++tot].from = s;
    e[tot].to = t;
    nex[tot] = first[s]; //当前边的下一条边是之前的最新的那条边
    first[s] = tot;      //最新的那条边更新
    //由于是树，所有上述过程的反过来重复一遍
    e[++tot].from = t;
    e[tot].to = s;
    nex[tot] = first[t];
    first[t] = tot;
} //加边函数,表示加一条s,t节点之间加一条边
//二叉树的构建

typedef struct node
{
    int data;
    node *ls;
    node *rs;
} binode, *bitree;
void build(bitree &root)
{
    int val;
    cin >> val;
    if (val == -1)
        root == NULL;
    else
    {
        root = (bitree)malloc(sizeof(binode));
        root->data = val;
        //递归建立左右子树
        build(root->ls);
        build(root->rs);
    }
}
//完全二叉树的构建
int tree[maxn]; //由于完全二叉树满足顺序存储结构，故而可以通过一个数组储存实现
//类似于堆，不多赘述
