#include <climits>
#include <iostream>

using namespace std;


// функция для вычисления суммы между двумя индексами
// в массиве

int sum(const int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;

}

// для n досок и k перегородок

int partition(int arr[], int n, int k)
{
    // базовые случаи
    // один раздел
    if (k == 1) return sum(arr, 0, n - 1);
    // одна доска
    if (n == 1)   return arr[0];
    int best = INT_MAX;
    for (int i = 1; i <= n; i++)
        best = min(best, max(partition(arr, i, k - 1),
                             sum(arr, i, n - 1)));
    return best;
}

int main()
{
    int arr[] = { 2,2,4,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;
    return 0;
}