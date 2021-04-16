#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <ctime>
//理想跳表
//缺点在于会产生比较突兀的数据,需要数据量大才适合使用随机数生成来构建跳表

using namespace std;
#define maxlevel 6
//随机生成lever的算法
struct node
{
    int data;
    int level;
    node *nex[maxlevel];
    node(int data, int level)
    {
        this->data = data;
        this->level = level;
        for (int i = 0; i < maxlevel; i++)
            nex[i] = NULL;
    }
}; //每个节点
struct skiplist
{
    node *head; //指向跳表的头节点
    int max_length;
    skiplist()
    {
        //head = NULL;
        max_length = 0;
        node *p = new node(INT_MIN, maxlevel); //首个节点
        //初始化head为一个5层的val(0)的node
        head = p;
    }
};

int hi_level()
{
    int k = 1;
    while (rand() % 2)
    {
        k++;
    }
    return k;
}
void insert(skiplist &l, int val)
{
    int level = hi_level();
    l.max_length++;
    node *cur = l.head;
    node *p = new node(val, level); //产生一个新节点
    node *last[maxlevel];
    for (int i = maxlevel - 1; i >= 0; i--)
    {
        while (cur->nex[i] != NULL && cur->nex[i]->data < val)
            cur = cur->nex[i];
        last[i] = cur;
    } //在每一层考虑加入
    if (cur->nex[0] == NULL)
    {
        for (int i = level - 1; i >= 0; i--)
            last[i]->nex[i] = p; //插入到最后的情况
    }
    else if (cur->nex[0]->data > val)
    {
        for (int i = level - 1; i >= 0; i--)
        {
            p->nex[i] = last[i]->nex[i];
            last[i]->nex[i] = p->nex[i];
        }
    }
} //跳表的插入操作'
//跳表的查询操作
void search(skiplist &l, int val)
{
    node *cur;
    cur = l.head;
    for (int i = maxlevel - 1; i >= 0; i--)
    {
        while (cur->nex[i] != NULL && cur->nex[i]->data < val)
            cur = cur->nex[i];
    }
    if (cur->nex[0]->data == val)
    {
        cout << "find the val" << endl;
        return;
    }
    cout << "val is not found" << endl;
    return;
}
void del(skiplist &l, int val)
{
    node *cur = l.head;
    node *last[maxlevel];
    node *target;
    for (int i = maxlevel - 1; i >= 0; i--)
    {
        while (cur->nex[i] != NULL && cur->nex[i]->data < val)
            cur = cur->nex[i];
        last[i] = cur;
        if (cur->nex[i] != NULL && cur->nex[i]->data == val)
            target = cur->nex[i];
    }
    for (int i = target->level - 1; i >= 0; i--)
        last[i] = target->nex[i];
    delete (target);
}
int main()
{
    srand((unsigned int)time(NULL));
    skiplist l;
    insert(l, 1);
    search(l, 1);
    del(l, 1);
    search(l, 1);
    return 0;
}
