#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define MAXN 10000
int n, m; //n个节点,m条边
//标准的实现临接表法的方法,还可以通过数组的形式实现
struct Linknode
{
    int vex;
    Linknode *next;
};
struct node
{
    int data;
    Linknode *head;
} node[MAXN];
void create()
{
    for (int i = 1; i <= n; i++)
        node[i].head = NULL;
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        Linknode *ptr = (Linknode *)malloc(sizeof(Linknode));
        ptr->vex = to;
        ptr->next = node[from].head;
        node[from].head = ptr;
    }
}
int main()
{
    cin >> n >> m;
    create();
    for (int i = 1; i <= n; i++)
    {
        Linknode *temp;
        temp = node[i].head;
        printf("node %d :", i);
        while (temp != NULL)
        {
            printf("->%d", temp->vex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}