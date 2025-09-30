#include <complex>
#include <iostream>
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

    while (current < 16)
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

    if (num > 9)
    {
        response += static_cast<char>(static_cast<int>('A') + num - 10);
    }
    else
    {
        response += static_cast<char>(static_cast<int>('0') + num);
    }

    return response;
}

void solve()
{
    double A, B, C;
    cin >> A >> B >> C;

    cout << to_hex(static_cast<int>(A)) << "\n";
    cout << to_hex(static_cast<int>(B)) << "\n";
    cout << to_hex(static_cast<int>(C)) << "\n";
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
