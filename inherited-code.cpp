#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException final : public std::exception {
    string n;

public:
    // Constructor to initialize the custom message
    explicit BadLengthException(const int nn) {
        n = std::to_string(nn);
    }

    // Override the what() method to return the custom message
    // noexcept is good practice for what() in modern C++
    [[nodiscard]] const char *what() const noexcept override {
        return n.c_str();
    }
};


bool checkUsername(const string &username) {
    bool isValid = true;
    const int n = username.size();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException &e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}
