#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int N, Q;
    map<string, string> attributes;
    vector<string> tokens = {};
    cin >> N >> Q;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;


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

            tokens.push_back(currentPath);

            string attrName, equal, value;

            while (ss >> attrName >> equal >> value) {
                if (attrName.data()) {
                    attributes[currentPath + "~" + attrName] = value.substr(1, value.size() - 3);
                }
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        string value;
        cin >> value;
        if (attributes.find(value) != attributes.end()) {
            cout << attributes[value] << "\n";
        } else {
            cout << "Not Found!\n";
        }
    }
}
