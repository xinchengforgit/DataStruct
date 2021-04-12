#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000];
int n;
void selectsort()
{
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[i])
                std::swap(a[i], a[j]);
        }
    return;
} //选择排序