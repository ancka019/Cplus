#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-9;

class Matrix
{
private:
    double** a;
    int n, m;
public:
    Matrix(int N, int M)
    {
        n = N;
        m = M;
        a = new double* [n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new double[m];
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
        }
    }
    int N()
    {
        return n;
    }
    int M()
    {
        return m;
    }
    double* operator [] (int index)
    {
        return getRow(index);
    }
    // получить строку матрицы
    double* getRow(int index)
    {
        if (index >= 0 && index < n)
            return a[index];
        return 0;
    }
};

// вывести матрицу на консоль
void printMatrix(Matrix& a)
{
    for (int i = 0; i < a.N(); i++)
    {
        for (int j = 0; j < a.M(); j++)
            printf("%6.1lf ", a[i][j]);
        puts("");
    }
}

void randomMatrix(Matrix& a)
{
    srand(time(0));
    for (int i = 0; i < a.N(); i++)
    {
        for (int j = 0; j < a.M(); j++)
        {
            int num = pow(-1, (rand() % 2)) * (rand() % 10);
            if (abs(num) < eps)
                a[i][j] = 0;
            else
                a[i][j] = num;
        }

    }
}

void gauss(Matrix& a)
{
    for (int i = 0; i < a.N(); i++)
    {
        // находим строку с максимальным по модулю "первым" элементом
        int iMax = i;
        for (int j = i + 1; j < a.N(); j++)
            if (abs(a[j][i]) > abs(a[iMax][i]))
                iMax = j;
        if (abs(a[iMax][i]) < eps)
            continue;
        for (int k = 0; k < a.M(); k++)
            swap(a[i][k], a[iMax][k]);

        //  вычитаем текущую строку из всех остальных
        for (int j = i + 1; j < a.N(); j++)
        {
            double q = -a[j][i] / a[i][i];
            for (int k = a.M() - 1; k >= i; k--)
                a[j][k] += q * a[i][k];
        }
    }

    // заменяем значения, близкие к нулю, на нули
    for (int i = 0; i < a.N(); i++)
        for (int j = 0; j < a.M(); j++)
            if (abs(a[i][j]) < eps)
                a[i][j] = 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Введите N(кол-во строк) и M(кол-во столбцов): ";
    cin >> n >> m;

    Matrix my_matrix = Matrix(n, m);
    randomMatrix(my_matrix);
    printMatrix(my_matrix);

    cout << "\n\nСтупенчатая матрица:\n";
    gauss(my_matrix);
    printMatrix(my_matrix);
}