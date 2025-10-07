#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map<string, string> attributes;
    vector<string> tagStack;

    // Parse HRML
    for (int i = 0; i < N; ++i)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;
        ss >> token;

        if (token[1] == '/')
        {
            if (!tagStack.empty()) {
                tagStack.pop_back();
            }
        }
        else
        {
            // Opening tag
            string tagName = token.substr(1); // Remove '<'

            // Build current tag path
            string currentPath;
            for (const auto& tag : tagStack)
            {
                currentPath += tag + ".";
            }
            currentPath += tagName;
            tagStack.push_back(tagName);

            // Parse attributes
            string attrName, equals, attrValue;
            while (ss >> attrName >> equals >> attrValue)
            {
                // Remove quotes from value
                attrValue = attrValue.substr(1, attrValue.length() - 3);

                // Remove trailing '>' if present
                if (attrValue.back() == '>')
                    attrValue.pop_back();

                string key = currentPath + "~" + attrName;
                attributes[key] = attrValue;
            }
        }
    }

    // Answer queries
    for (int i = 0; i < Q; ++i)
    {
        string query;
        cin >> query;

        if (attributes.contains(query))
        {
            cout << attributes[query] << "\n";
        }
        else
        {
            cout << "Not Found!\n";
        }
    }

    return 0;
}