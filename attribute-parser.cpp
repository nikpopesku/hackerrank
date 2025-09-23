#include <iostream>
#include <limits>

using namespace std;


int main()
{
    int N, Q;
    string s, current;

    cin >> N >> Q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i)
    {
        getline(std::cin, current);
        s += current;
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> current;
    }

    cout << s << "\n";


    return 0;
}
