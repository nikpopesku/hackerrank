#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> parseInts(string s)
{
    stringstream ss;
    ss.str(s);
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
    const vector a = parseInts(s);

    for (const int i : a) {
        cout << i << "\n";
    }
    return 0;
}
