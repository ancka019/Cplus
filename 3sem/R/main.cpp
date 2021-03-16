#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
    Complex(double realPart = 0, double imaginaryPart = 0)
    {
        this->realPart = realPart;
        this->imaginaryPart = imaginaryPart;
    };
    void enterComplex()
    {
        double x = 0;
        double y = 0;
        cout << "Enter Complex: ";
        cin >> x >> y;
        this->realPart = x;
        this->imaginaryPart = y;

    };
    void printComplex()
    {
        cout << this->realPart << " + " << this->imaginaryPart << "i ";
    };
    void Exp(){
        cout <<exp(realPart) * cos(imaginaryPart);
        cout << "+" << exp(realPart) * sin(imaginaryPart) << "i";
    }
    Complex& operator=(Complex const& a)
    {
        if (this != &a)
        {
            realPart = a.realPart;
            imaginaryPart = a.imaginaryPart;
        };
        return *this;
    };
    double getReal() const {
        return realPart;
    };
    double getImaginary() const {
        return imaginaryPart;
    };
private:
    double realPart;
    double imaginaryPart;
};

Complex operator+(Complex const& a, Complex const& b)
{
    return Complex(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
};
Complex operator-(Complex const& a, Complex const& b)
{
    return Complex(a.getReal() - b.getReal(), a.getImaginary() - b.getImaginary());
};
Complex operator*(Complex const& a, Complex const& b)
{
    return Complex(a.getReal() * b.getReal() - a.getImaginary() * b.getImaginary(), a.getImaginary() * b.getReal() + b.getImaginary() * a.getReal());
};
Complex operator/(Complex const& a, Complex const& b)
{
    return Complex((a.getReal() * b.getReal() + a.getImaginary() * b.getImaginary()) / (b.getReal() * b.getReal() + b.getImaginary() * b.getImaginary()), (b.getReal() * a.getImaginary() - b.getImaginary() * a.getReal()) / (b.getReal() * b.getReal() + b.getImaginary() * b.getImaginary()));
};

int main()
{
    int x, y;
    cin >> x;
    cin >> y;
    Complex D(x,y);
    D.Exp();
}