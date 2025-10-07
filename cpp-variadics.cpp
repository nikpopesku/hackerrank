#include <iostream>
using namespace std;

template<bool... digits>
int reversed_binary_value() {
    bool arr[] = {digits...};
    int result = 0;
    int power = 1;
    for (int i = 0; i < sizeof...(digits); ++i) {
        if (arr[i]) {
            result += power;
        }
        power *= 2;
    }
    return result;
}


template<int n, bool... digits>
struct CheckValues {
    static void check(int x, int y) {
        CheckValues<n - 1, false, digits...>::check(x, y);
        CheckValues<n - 1, true, digits...>::check(x, y);
    }
};

template<bool... digits>
struct CheckValues<0, digits...> {
    static void check(const int x, const int y) {
        const int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x ? 1 : 0);
    }
};

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}