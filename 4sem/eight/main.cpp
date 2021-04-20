#include <iostream>

using namespace std;


// вычисляем максимальное украденное значение

int maxLoot(int *h, int n)

{
    if (n == 0) return 0;
    if (n == 1) return h[0];
    if (n == 2) return max(h[0], h[1]);

    // count [i] представляет макс. украденное значение после достижения дома i
    int count[n];
    count[0] = h[0];
    count[1] = max(h[0], h[1]);
    for (int i = 2; i<n; i++)
        count[i] = max(h[i]+count[i-2], count[i-1]);
    return count[n-1];
}

int main()
{
    int H[] = {50, 1, 1, 12};
    int n = sizeof(H)/sizeof(H[0]);
    cout << "Maximum: " << maxLoot(H, n);
    return 0;
}