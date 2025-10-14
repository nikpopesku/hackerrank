#include <iostream>
#include <bitset>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, S, P, Q;
    constexpr ull val = 1ULL << 31;

    cin >> N >> S >> P >> Q;

    ull last = S % val;
    bitset<(1ULL << 31)> seen;

    seen[last] = true;
    ull count = 1;

    for (ull i = 1; i < N; ++i)
    {
        last = (last * P + Q) % val;

        if (seen[last])
        {
            break;
        }

        seen[last] = true;
        ++count;
    }

    cout << count << "\n";
}
