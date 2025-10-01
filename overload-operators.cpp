#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

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

    [[nodiscard]] int get_real() const
    {
        return a;
    }

    [[nodiscard]] int get_imaginary() const
    {
        return b;
    }
};


ostream& operator<<(ostream& out, const Complex c)
{
    out << c.get_real() << "+i" << c.get_imaginary();

    return out;
}

vector<string> splitString(const string& s, const char delimiter)
{
    vector<string> tokens;
    istringstream ss(s);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    Complex c;

    for (int i = 0; i < 2; ++i)
    {
        string text;
        cin >> text;

        if (text.empty())
        {
            break;
        }

        vector<string> result = splitString(text, '+');
        result[1].erase(0, 1);
        Complex b(stoi(result[0]), stoi(result[1]));
        c = c + b;
    }

    cout << c << endl;

    return 0;
}
