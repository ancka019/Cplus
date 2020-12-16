#include <iostream>

using namespace std;

int main() {

    int bracketsAmount;

    cout << "Please enter amount of bracket pairs:";
    cin >> bracketsAmount;

    cout << "Your line will have the following model:\n";
    for (int i = 0; i < bracketsAmount; ++i) {
        if (i != 0) {
            cout << " & ";
        }
        cout << "(x" << 2*i+1 << "|x" << 2*i+2 << ")";
    }
    cout << " = true\n\n";

    cout << "All possible solutions:\n";
    for (int i = 0; i < bracketsAmount; ++i) {
        cout << "x" << 2*i+1 << "/x" << 2*i+2 << " = true/false OR true/true OR false/true\n";
    }

    cout << "\nCombination of any of those pairs gives us a solution for initial equation.";
    return 0;
}
