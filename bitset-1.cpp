#include <set>
#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll N, S, P, Q;
    constexpr ll val = 2 << 31;
    set<ll> s;


    cin >> N >> S >> P >> Q;

    ll last = S % val;
    s.insert(last);

    for (ll i  = 1; i < N; ++i)
    {
        last = last * P + Q % val;
        s.insert(last);
    }

    return s.size();
}
