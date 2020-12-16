#include <iostream>

#define N 13
using namespace std;

int main() {
    int arr[N];
    int i, k, num, frq, max_frq, min_frq;
    for (i=0; i<N; i++) {
        cin >> arr[i];
    }

    num = arr[0];
    min_frq = 0;
    for (i = 0; i < N; i++) {
        frq = 1;
        for (k = 0; k<N; k++) {
            if (arr[i] == arr[k] && i != k) {
                frq += 1;
            }
        }
        if (frq == 1|| (frq == 2 && min_frq == 0)){
            min_frq = frq;
            num = arr[i];
        }
    }

    if (min_frq == 1 || min_frq == 2)
        cout << min_frq << " раз(а) встречается число " << num;
    else{
        max_frq = 1;
        min_frq = 0;
        for (i=0; i < N; i++) {
            frq = 1;
            for (k = 0 ; k<N; k++) {
                if (arr[i] == arr[k] && i != k)
                    frq += 1;
            }
            if (frq > max_frq) {
                max_frq = frq;
            }
        }
        for (i=0; i < N; i++) {
            frq = 1;
            for (k = 0; k<N; k++) {
                if (arr[i] == arr[k] && i != k)
                    frq += 1;
            }
            if (frq  < max_frq) {
                min_frq = frq;
                num = arr[i];
            }
        }
        cout << min_frq << " раз(а) встречается число " << num;
    }
}