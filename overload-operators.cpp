#include <iosfwd>
#include <iostream>
#include <ostream>

using namespace std;


class Complex
{
public:
    int a = 0, b = 0;

    Complex operator+(const Complex& other)
    {
        a += other.a;
        b += other.b;

        return *this;
    }
};


ostream& operator<<(const ostream& out, const Complex c)
{
    out << c.a << "+i" << c.b << "\n";

    return out;
}

int main()
{
    Complex c;

    cout << c;

    return 0;
}
