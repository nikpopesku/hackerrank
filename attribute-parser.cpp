#include <iostream>
#include <limits>

using namespace std;

string extract(const string& query, const string& s)
{
    return query + '2';
}

int main()
{
    int N, Q;
    string s, current, query;

    cin >> N >> Q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i)
    {
        getline(std::cin, current);
        s += current;
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> query;

        cout << extract(query, s) << "\n";
    }

    return 0;
}
