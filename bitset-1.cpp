#include <set>
#include <iostream>
using namespace std;

#define ull unsigned long long

int main()
{
    ull N, S, P, Q;
    constexpr ull val = 1 << 31;
    set<ull> s;


    cin >> N >> S >> P >> Q;

    ull last = S % val;
    s.insert(last);

    for (ull i = 1; i < N; ++i)
    {
        last = last * P + Q % val;
        s.insert(last);
    }

    cout << s.size() << "\n";
}
