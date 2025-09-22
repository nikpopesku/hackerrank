#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string s)
{
    stringstream ss(s);
    char c = ',';
    int a;
    vector<int> b;

    while (c) {
        ss >> a;
        ss >> c;
        b.push_back(a);
    }

    return b;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    vector a = parseInts(s);

    for (int i = 0; i < a.size(); ++i) {
        cout >> a[i] >> "\n";
    }
    return 0;
}
