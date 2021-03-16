#include <iostream>
#include <cmath>
using namespace std;

int** create(int n)
{
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[10];
        for (int j = 0; j < 10; j++)
            a[i][j] = 0;
    }
    return a;
}

int* access(int** a, int row, int column, int n)
{
    static int dummy;
    dummy = 0;

    if (row >= n || row < 0 || column < 0 || column >= n)
    {
        exit(1);
    }
    else if (abs((row / 10) - (column / 10)) >= 1)
    {
        return &dummy;
    }
    return &(a[row][column % 10]);
}

void destroy(int** a, int n)
{
    for (int i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}

int main()
{
    cout << "Введите n, кратное 10: ";
    int n;
    cin >> n;

    int** a = create(n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            *access(a, row, col, n) = 2;
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << *(access(a, row, col, n)) << " ";
        }
        cout << "\n";
    }

    destroy(a, n);
}