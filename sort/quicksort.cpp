#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>
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
            i++;
            j--; //这两个别忘了
        }
    } while (i <= j);
    if (i < r)
        quicksort(i, r);
    if (j > l)
        quicksort(l, j);
    return;
} //快排()
int main()
{
    srand((unsigned int)time(NULL));
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        a[i] = rand() % 100;
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    quicksort(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
