#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
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
int main()
{
    srand((unsigned int)time(NULL));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 100;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    msort(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}