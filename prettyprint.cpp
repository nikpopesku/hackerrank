#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

string to_hex(int num)
{
    if (num == 0)
    {
        return "0x0";
    }

    string response = "0x";
    int degree = 0;
    int dozen = 1;
    int current = num / dozen;

    while (current >= 16)
    {
        ++degree;
        dozen *= 16;
        current = num / dozen;
    }

    while (degree >= 0)
    {
        if (const int value = num / dozen; value > 9)
        {
            response += static_cast<char>(static_cast<int>('A') + value - 10);
        }
        else
        {
            response += static_cast<char>(static_cast<int>('0') + value);
        }

        --degree;
        num %= dozen;
        dozen /= 16;
    }

    return response;
}

string to_val(const double num)
{
    string response;

    if (num > 0)
    {
        response += "+";
    }
    else
    {
        response += "-";
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << num;

    response += oss.str();
    string underscore;

    for (int i = 0; i < 15 - response.size(); ++i)
    {
        underscore += '_';
    }

    return underscore + response;
}

void solve()
{
    double A, B, C;
    cin >> A >> B >> C;

    cout << to_hex(static_cast<int>(A)) << "\n";
    cout << to_val(B) << "\n";
    cout << setprecision(9) << scientific << uppercase << C << "\n";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}
