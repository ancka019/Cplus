#include <iostream>

using namespace std;

template <class CalcElements>
CalcElements add(CalcElements a, CalcElements b)
{
    CalcElements result;
    result = a + b;
    return result;
}

template <class CalcElements>
CalcElements diff(CalcElements a, CalcElements b)
{
    CalcElements result;
    result = a - b;
    return result;
}

template <class CalcElements>
CalcElements divide(CalcElements a, CalcElements b)
{
    CalcElements result;
    result = a / b;
    return result;
}

template <class CalcElements>
CalcElements prod(CalcElements a, CalcElements b)
{
    CalcElements result;
    result = a * b;
    return result;
}

template <class CalcElements>
CalcElements Concatenate(CalcElements mas, CalcElements str)
{
    CalcElements result;
    result = mas + str;
    return result;
}

int main(void)
{
    char mas[20] = {'3', '+'};
    string str = "4+6";
    cout << Concatenate<string>(mas, str) << endl;
    cout<<add<int>(10,20)<<endl;
    cout<<add<float>(10.5,20)<<endl;
    cout<<diff<float>(5.4,2.3)<<endl;
    cout<<diff<float>(5,2.3)<<endl;
    cout<<prod<int>(4,5)<<endl;
    cout<<prod<float>(2.5,2)<<endl;
    cout<<divide<int>(9,3)<<endl;
    cout<<divide<float>(5,2)<<endl;
    cin.get();

    return 0;
}
