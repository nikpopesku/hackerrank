#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

string extract(const string& query, const string& s)
{
    stringstream ss;
    ss.str(s);
    string response;

    do
    {
        response = query + '2';
    } while (1);

    return response;
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
