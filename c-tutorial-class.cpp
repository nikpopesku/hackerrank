#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
    class Student
    {
    private:
        int age = 0;
        string first_name;
        string last_name;
        int standard = 0;

    public:
        [[nodiscard]] int get_age() const
        {
            return age;
        }

        void set_age(const int a)
        {
            age = a;
        }

        string get_first_name()
        {
            return first_name;
        }

        void set_first_name(const string& name)
        {
            first_name = name;
        }

        string get_last_name()
        {
            return last_name;
        }

        void set_last_name(const string& a)
        {
            last_name = a;
        }

        [[nodiscard]] int get_standard() const
        {
            return standard;
        }

        void set_standard(const int a)
        {
            standard = a;
        }

        [[nodiscard]] string to_string() const
        {
            stringstream ss;
            ss << age << ',' << first_name << ',' << last_name << ',' << standard;

            return ss.str();
        }
    };

    Student s;
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;
    s.set_age(age);
    s.set_first_name(first_name);
    s.set_last_name(last_name);
    s.set_standard(standard);

    cout << s.get_age() <<"\n";
    cout << s.get_last_name() << ", " << s.get_first_name() << "\n";
    cout << s.get_standard() << "\n\n";
    cout << s.to_string();
    return 0;
}
