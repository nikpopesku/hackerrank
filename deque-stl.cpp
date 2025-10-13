#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], const int n, const int k)
{
    deque<int> dq;

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(arr[i]);
    }

    for (int i = k; i < n; ++i)
    {
        cout << dq.front() << " ";

        while (!dq.empty() && dq.front() < i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(arr[i]);
    }

    cout << arr[dq.front()] << "\n";
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
