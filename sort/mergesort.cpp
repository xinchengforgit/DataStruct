#include <cstdio>
#include <algorithm>
#define maxn 1000000
int a[maxn];
int temp[maxn];
void msort(int b, int e)
{
    if (b == e)
        return;
    int mid = (b + e) / 2;
    msort(b, mid);
    msort(mid + 1, e);
    int i = b, j = mid + 1, k = b;
    while (i <= mid && j <= e)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= e)
        temp[k++] = a[j++];
    for (int i = b; i <= e; i++)
        a[i] = temp[i];
    return;
}