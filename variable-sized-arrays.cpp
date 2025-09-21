#include <vector>
#include <iostream>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> a[100000];
    int n, q, k;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        vector<int> b(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> b[j];
        }

        a[i] = b;
    }

    for (int i = 0; i < q; ++i)
    {
        int row, col;
        cin >> row >> col;

        cout << a[row][col] << "\n";
    }

    return 0;
}
