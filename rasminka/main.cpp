#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число";
    cin >> n;
    for( int i = 1; i <= n/2; i++){
        for(int j = 2; j <= n/2 ; j++){
            if(j*i == n and j*i - j - i == 0){
                cout << j<< " and " << i;
            }
        }
    }
    return 0;
}
