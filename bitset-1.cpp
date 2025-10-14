#include <bitset>
#include <iostream>
#include <memory>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, S, P, Q;
    constexpr ull val = 1 << 25;
    bitset<(val)> seen;
    ull counter = 1;


    cin >> N >> S >> P >> Q;

    ull last = S % val;

    for (ull i = 1; i < N; ++i)
    {
        last = (last % val) * (P % val) % val + Q % val;

        if (seen[last])
        {
            break;
        }

        ++counter;
        seen[last] = true;
    }

    cout << counter << "\n";
}
