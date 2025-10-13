#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], const int n, const int k)
{
    deque<int> dq; // stores indices, not values

    // Process first k elements
    for (int i = 0; i < k; ++i)
    {
        // Remove elements from back while current element is greater
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process remaining elements
    for (int i = k; i < n; ++i)
    {
        // The front element is the maximum of previous window
        cout << arr[dq.front()] << " ";

        // Remove elements outside current window
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Remove elements smaller than current element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    // Print maximum of last window
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
