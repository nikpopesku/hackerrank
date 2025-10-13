#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], const int n, const int k)
{
    deque<int> dq;

    for (int i = 0; i < n; ++i)
    {
        if (dq.size() >= k)
        {
            dq.pop_front();
        }

        if (dq.size() < k)
        {
            dq.push_back(arr[i]);
        }

        if (i >= k - 1)
        {
            auto max_it_vector = ranges::max_element(dq);
            cout << *max_it_vector << " ";
        }
    }

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        printKMax(arr, n, k);
    }

    return 0;
}
