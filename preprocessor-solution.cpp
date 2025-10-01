#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#define foreach(v, i) for(int i = 0; i < v.size(); ++i)
#define io(v) cin >> v
#define INF 1e8
#define toStr(str) #str
#define FUNCTION(name, op) inline void name(int& a, int b) { a = a op b ? a : b; }
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    foreach(v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}
