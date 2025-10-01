#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#define foreach(v, i) for(int i = 0; i < v.size(); ++i)
#define io(v)[i]; cin >> v[i];
#define INF 1e8
#define minimum(mn, v[i]); mn = mn < v[i] ? mn : v[i];
#define maximum(mn, v[i]); mn = mn > v[i] ? mn : v[i];
#define toStr(Result =) "Result = "
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
