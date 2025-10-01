#include <iosfwd>
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


ostream& operator<<(const ostream& out, Complex c)
{
    out << c.a << "+i" << c.b;

    return &out;
}

int main()
{
    Complex c;

    return 0;
}
