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


ostream operator<<(const ostream& out, Complex c)
{
    out << c.a << "+i" << c.b << "\n";

    return out;
}


ostream& operator<<(const ostream& out, const Complex c)
{
    out << c.a << "+i" << c.b << "\n";

    return out;
}

int main()
{
    Complex c, b;
    int real, img;

    while (true)
    {
        getline(cin, real, "+i");
        if (!real)
        {
            break;
        }

        getline(cin, img);
        b.a = real;
        b.b = img;
        c += b;
    }

    cout << c;

    return 0;
}
