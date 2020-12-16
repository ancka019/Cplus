#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int Palindrome(const string &text) {
    int d;
    d = text.length();
    d = d/2;
    for (int i = 0; i < d; ++i){
        char mistake;
        string line;
        if(tolower(text[i]) != tolower(text[text.length() - i - 1 ])){
            mistake = text[i];
            for(char j : text){
                if (tolower(j) != tolower(mistake)){
                    line += j;
                }
            }
            for (int j = 0; j < line.length() / 2; ++j) {
                if (tolower(line[j]) != tolower(mistake)) {
                    if (tolower(line[i]) != tolower(line[line.length() - i - 1])){
                        cout << "нельзя сделать палиндромом" << endl;
                        return -1;
                    }
                }
            }
            cout << "удовлетворяет условием задачи" << endl;
            return 0;
        }
    }
    char g;
    g = (text[d]);
    if (tolower(g) != tolower(' ')){
        if (tolower(g) == tolower(text[d-1]) | tolower(g) == tolower(text[d+1])){
            cout << "изначально палиндром" << endl;
            return -1;
        }
        else{
            cout << "удовлетворяет условием задачи" << endl;
            return 0;
        }
    }
    cout << "изначально палиндром" << endl;
    return -1;
}

int main(){
    char text[100];
    cout << "Введите строку:" << endl;
    cin.getline(text,100);
    cout << Palindrome(text);
    return 0;
}