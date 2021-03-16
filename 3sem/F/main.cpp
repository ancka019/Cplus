#include <iostream>
#include <string>
using namespace std;

void calc(int len, char* opz)
{
    cout << opz;
    string answer;
    float stack[100];
    // sp = индекс ячейки, куда будет push-иться очередное число
    int sp = 0;      // (sp-1) = индекс вершины стека
    for (int i = 0; i <= len; i++) {
        if (opz[i] == 'x')
            break;
        else if (opz[i] == ' ' || opz[i] == '\n')
            continue;

        else if (opz[i] == '+') {
            stack[sp - 2] = stack[sp - 2] + stack[sp - 1];
            sp--;
            continue;
        }
        else if (opz[i] == '-') {
            stack[sp - 2] = stack[sp - 2] - stack[sp - 1];
            sp--;
            continue;
        }
        else if (opz[i] == '*') {
            stack[sp - 2] = stack[sp - 1] * stack[sp - 2];
            sp--;
            continue;
        }
        else if (opz[i] == '/') {
            stack[sp - 2] = stack[sp - 2] / stack[sp - 1];
            sp--;
            continue;
        }

        else {
            for (int j = i; j < len; j++) {
                if (isdigit(opz[j]) || opz[j] == ',') {
                    answer += opz[j];
                }
                else {
                    i = j;
                    break;
                }
            }
            stack[sp] = stof(answer);
            sp++;
            answer.clear();
        }
    }

    cout << endl;
    cout <<  stack[sp - 1] << endl;
}

int main() {
    int n;
    char opz[100];
    cout << "Посчитать выражение по опз - 1  или обычной формы - 2";
    cin >> n;
    if (n == 2) {
        int s = 0, e = 0;
        char vr[100], stack[100];
        cout << "Введите выражение:";
        cin >> vr;
        for (int i = 0; vr[i] != '\0'; i++)
            switch (vr[i]) {
                case '+':
                    while ((s != 0) && (stack[s - 1] != '(')) {
                        opz[e] = stack[s - 1];
                        e++;
                        s--;
                    }
                    stack[s] = '+';
                    s++;
                    break;

                case '-':
                    while ((s != 0) && (stack[s - 1] != '(')) {
                        opz[e] = stack[s - 1];
                        e++;
                        s--;
                    }
                    stack[s] = '-';
                    s++;
                    break;
                case '*':

                    while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-')) {
                        opz[e] = stack[s - 1];
                        e++;
                        s--;
                    }
                    stack[s] = '*';
                    s++;
                    break;
                case '/':

                    while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-')) {
                        opz[e] = stack[s - 1];
                        e++;
                        s--;
                    }
                    stack[s] = '/';
                    s++;

                    break;
                case '(': {
                    stack[s] = '(';
                    s++;
                    break;
                }
                case ')':

                    while ((stack[s - 1] != '(') && (s != 0)) {
                        opz[e] = stack[s - 1];
                        e++;
                        s--;
                    }
                    stack[s - 1] = ' ';
                    s--;
                    break;


                default: {
                    opz[e] = vr[i];
                    e++;
                    if ((vr[i + 1] == '+') ||
                        (vr[i + 1] == '-') ||
                        (vr[i + 1] == '*') ||
                        (vr[i + 1] == '/') ||
                        (vr[i + 1] == '(') ||
                        (vr[i + 1] == ')')) {
                        opz[e] = ' ';
                        e++;
                    }
                }
            }
        opz[e] = ' ';
        e++;
        while (s != 0) {
            opz[e] = stack[s - 1];
            e++;
            s--;
        }
        cout << "Обратная польская запись: ";
        opz[e] = 'x';
        for (int i = 0; i < e; i++) {
            cout << opz[i] ;
        }
        calc(e, opz);
    }
    else if (n == 1){
        cin >> opz;
        int i, len ;
        len = 0;
        for(i = 0; opz[i] != 'x'; i++){
            len += 1;
        }
        cout << len << endl;
        calc(, opz);
    }
}