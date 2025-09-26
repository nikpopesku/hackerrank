#include<bits/stdc++.h>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
    int l, b, h;

public:
    Box() {
        l = b = h = 0;
    }

    Box(const int length, const int breadth, const int height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box(const Box &other) {
        l = other.l;
        b = other.b;
        h = other.h;
    }

    [[nodiscard]] int getLength() const {
        return l;
    }

    [[nodiscard]] int getBreadth() const {
        return b;
    }

    [[nodiscard]] int getHeight() const {
        return h;
    }

    [[nodiscard]] long long CalculateVolume() const {
        return static_cast<long long>(l) * static_cast<long long>(b) * static_cast<long long>(h);
    }

    bool operator<(const Box &other) const {
        if (l < other.l) {
            return true;
        }

        if (l > other.l) {
            return false;
        }

        if (b < other.b) {
            return true;
        }

        if (b > other.b) {
            return false;
        }

        if (h < other.h) {
            return true;
        }

        return false;
    }
};


ostream &operator<<(std::ostream &os, const Box &b) {
    os << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();

    return os;
}

void check2() {
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser\n";
            } else {
                cout << "Greater\n";
            }
        }
        if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main() {
    check2();
}
