#include <iostream>
#include <ostream>

using namespace std;


class Complex
{
public:
    int a = 0, b = 0;

    Complex& operator+(const Complex& other)
    {
        a += other.a;
        b += other.b;

        return *this;
    }
};


ostream& operator<<(ostream& out, const Complex c)
{
    out << c.a << "+i" << c.b << "\n";

    return out;
}

int main()
{
    Complex c, b;

    while (true)
    {
        int img;
        int real;
        getline(cin, real, "+i");
        if (!real)
        {
            break;
        }

        getline(cin, img);
        b.a = real;
        b.b = img;
        c = c + b;
    }

    cout << c;

    return 0;
}
