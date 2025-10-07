#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, Q;
    map<string, string> attributes;
    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;
        vector<string> tokens = {};


        ss >> token;

        if (token[1] == '/') {
            tokens.pop_back();
        } else {
            string currentPath;

            token = token.substr(1);

            for (auto t: tokens) {
                currentPath += t + ".";
            }
            currentPath += token;

            string attrName, equal, value;
            ss >> attrName >> equal >> value;

            if (attrName.data()) {
                attributes[currentPath + "~" + attrName] = value;
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        string value;
        cin >> value;
        if (attributes.contains(value)) {
            cout << attributes[value] << "\n";
        } else {
            cout << "Not Found!\n";
        }
    }
}
