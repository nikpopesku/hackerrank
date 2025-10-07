#include <iostream>
#include <bits/stl_map.h>
using namespace std;

enum class Fruit { apple, orange, pear };

enum class Color { red, green, orange };

template<typename T>
struct Traits;

// Specialization for Fruit
template<>
struct Traits<Fruit> {
    static string name(const int index) {
        switch (index) {
            case 0: return "apple";
            case 1: return "orange";
            case 2: return "pear";
            default: return "unknown";
        }
    }
};

// Specialization for Color
template<>
struct Traits<Color> {
    static string name(const int index) {
        switch (index) {
            case 0: return "red";
            case 1: return "green";
            case 2: return "orange";
            default: return "unknown";
        }
    }
};


string main() {
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
