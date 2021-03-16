#include <iostream>
#include <string>

using namespace std;

int main()
{


    int a = 0x41424344;
    char *p = (char*)&a;

    cout << p[0] << ' '<< p[1] << ' ' << p[2] << ' '<< p[3] << "\n";

    if (p[0] < p[1] && p[1] < p[2] && p[2] < p[3])
        cout << "Big Endian\n";
    else if (p[0] > p[1] && p[1] > p[2] && p[2] > p[3])
        cout << "Little-endian\n";
    else
        cout << "Mixed Endian\n";
}
