#include <iostream>
#include <string>
#include <utility>
using namespace std;

template <class T>
class AddElements
{
    T element;

public:
    explicit AddElements(T e) : element(e)
    {
    }

    T add(T another)
    {
        return element + another;
    }
};

template <>
class AddElements<string>
{
    string element;

public:
    explicit AddElements(string  e) : element(std::move(e))
    {
    }

    [[nodiscard]] string concatenate(const string& other) const
    {
        return element + other;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << '\n';
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << '\n';
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << '\n';
        }
    }
    return 0;
}
