#include <cstdio>
#include <algorithm>
#define maxn 100000
int a[maxn];
void quicksort(int l, int r)
{
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    do
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            std::swap(a[i], a[j]);
        }
    } while (i <= j);
    if (i < r)
        quicksort(i, r);
    if (j > l)
        quicksort(l, j);
    return;
} //快排()
