#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    int d = 0;
    int lengthMax = 0, length = 1;
    int n;
    cout << "Введите длину массива";
    cin >> n;
    int mas[n];
    for(int i = 0; i < n; i++){
        mas[i] = 2 + rand() % 10;
        cout << mas[i] << endl;
    }
    for( int i = 1;i < n; i++)
    {
        if (mas[i] % mas[i-1] == 0 and d == 0){
            d = mas[i] / mas[i-1];
            length += 1;
        }
        else if( d != 0){
            if ( d == mas[i] / mas[i-1] and mas[i] == mas[i-1] * d){
                length +=1;
            }
            else{
                if ( length > lengthMax){
                    lengthMax = length;
                }
                d = mas[i] / mas[i-1];
                length = 1;
            }
        }
    }
    if (length > lengthMax){
        cout <<"Max length " << length;
    }
    else {
        cout <<"Max length " << lengthMax;
    }
    return 0;
}
