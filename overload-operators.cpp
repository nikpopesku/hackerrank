#include <iostream>
#include <ostream>
#include <string>

using namespace std;


class Complex
{
    int a = 0, b = 0;

public:
    Complex() = default;
    Complex(const int a, const int b) : a(a), b(b)
    {
    }

    Complex& operator+(const Complex& other)
    {
        a += other.a;
        b += other.b;

        return *this;
    }
};


ostream& operator<<(ostream& out, const Complex c)
{
    out << c.a << "+i" << c.b;

    return out;
}

int main()
{
    Complex c;

    while (true)
    {
        string img;
        string real;
        getline(cin, real);
        if (real == "")
        {
            break;
        }

        getline(cin, img);
        Complex b(stoi(real), stoi(img));
        c = c + b;
    }

    cout << c << endl;

    return 0;
}
