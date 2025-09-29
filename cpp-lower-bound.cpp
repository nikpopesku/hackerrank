#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int Q, val;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        cin >> val;
        auto it = lower_bound(v.begin(), v.end(), val);

        cout << (v[it - v.begin()] == val ? "Yes" : "No") << " " << it - v.begin() + 1 << "\n";
    }

    return 0;
}
