#include<iostream>
using namespace std;
int a[100];


int main() {
    int n;
    cout << "Введите длину массива:";
    cin >> n;
    int m = n*2;
    int max_sum[m][n];
    cout << "Введите элементы массива";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        for( int j = 0; j < n; j++){
            max_sum[i][j] = 0;
            cout << max_sum[i][j] << endl;
        }
    }
    cout << max_sum;
    int cur_sum;
    int j = 0;
    int t = 0;
    for (int i = 0; i < n; i++){
        cur_sum = a[i];
        while( j < n){
            if (j != i){
                if( ((j -1) != i) || (j +1) != i){
                    max_sum[i][j] = cur_sum + a[j];

                }
            }
            j += 1;
        }
        j = i+ 1;
    }
    for(int i = 0; i < n; i++){
        cout << max_sum[i] << endl;
    }
}