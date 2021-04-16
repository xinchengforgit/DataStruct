#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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
        now = next;
    }
    return ret;
}
int pop1()
{
    int ret = heap[1];
    heap[1] = heap[heap_size--];
    int now = 1, next;
    while (now * 2 <= heap_size)
    {
        next = now * 2;
        if (next < heap_size && heap[next + 1] < heap[next])
            next++;
        if (heap[next] > heap[now])
            return ret;
        std::swap(heap[next], heap[now]);
        now = next;
    }
    return ret;
}
void heap_sort()
{
    int k = heap_size;
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", pop1());
    }
} //堆排序每次从堆顶取出一个元素,这里有个坑需要拿k赋值给heap_size(),因为heap_size在不断改变
int main()
{
    int a[105];
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= 13; i++)
    {
        a[i] = rand() % 100;
        update(a[i]);
    }
    for (int i = 1; i <= 13; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 1; i <= 13; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
    printf("%d\n", heap_size);
    heap_sort();
    return 0;
}