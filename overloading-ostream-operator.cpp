#include <iostream>
#include <utility>

using namespace std;

class Person
{
public:
    Person(string  first_name, string  last_name) : first_name_(std::move(first_name)), last_name_(std::move(last_name))
    {
    }

    [[nodiscard]] const string& get_first_name() const
    {
        return first_name_;
    }

    [[nodiscard]] const string& get_last_name() const
    {
        return last_name_;
    }

private:
    string first_name_;
    string last_name_;
};

ostream& operator<<(ostream& os, const Person& p)
{
    cout << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();

    return os;
}


int main()
{
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    const auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
