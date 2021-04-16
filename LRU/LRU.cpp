#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define capacity 10

struct node
{
    node *pre;
    node *nex;
    int val;
    int key;
    node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->pre = NULL;
        this->nex = NULL;
    }
};
struct lru
{
    map<int, node *> m;
    node *head;
    node *tail;
    int size; //缓存的最大值
    lru()
    {
        this->size = capacity;
        this->head = NULL;
        this->tail = NULL;
    }
    void remove(node *p)
    {
        if (p->pre != NULL)
        {
            p->pre->nex = p->nex;
        }
        else
        {
            head = p->nex; //此时p是首个节点
        }
        if (p->nex != NULL)
        {
            p->nex->pre = p->pre;
        }
        else
        {
            tail = p->pre;
        }
    }
    void sethead(node *p)
    {
        p->nex = head;
        p->pre = NULL;
        if (head != NULL)
        {
            head->pre = p;
        }
        head = p;
        if (tail == NULL)
        {
            tail = head;
        } //如果是首个节点
    }
    int get(int key)
    {
        auto it = m.find(key);
        if (it != m.end())
        {
            node *p = it->second;
            remove(p);
            sethead(p);
            return p->val;
        }
        else
        {
            return -1; //没查到返回-1
        }
    }
    void set(int key, int val)
    {
        auto it = m.find(key);
        if (it != m.end())
        {
            node *p = it->second;
            p->val = val;
            remove(p);
            sethead(p);
        } //查到了的话
        else
        {
            node *p = new node(key, val);
            if (m.size() >= size)
            {
                auto iter = m.find(tail->key); //node要key的原因s
                remove(tail);
                m.erase(iter);
            }
            sethead(p);
            m[key] = p;
        }
    }
};
int main()
{
    lru mylru;
    mylru.set(1, 5);
    mylru.set(2, 7);
    printf("%d", mylru.get(1));
    return 0;
}
