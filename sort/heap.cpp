#include <cstdio>
#include <algorithm>
using namespace std;
int heap[10000];
int heap_size;
void update(int a)
{
    heap[++heap_size] = a;
    int now = heap_size;
    while (now != 1)
    {
        if (heap[now / 2] < heap[now])
            return;
        swap(heap[now], heap[now / 2]);
        now /= 2;
    }
    return;
}
int pop()
{
    int ret = heap[1];
    heap[1] = heap[heap_size--];
    int now = 1;
    int next;
    while (now * 2 <= heap_size)
    {
        next = now * 2;
        if (next < heap_size && heap[next + 1] < heap[next])
            next += 1;
        if (heap[now] < heap[next])
            return ret;
        swap(heap[now], heap[next]);
    }
    return ret;
}

void heap_sort()
{
    for (int i = 1; i <= heap_size; i++)
        printf("%d ", pop());
} //堆排序每次从堆顶取出一个元素