#include <iostream>
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
            AddElements myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
