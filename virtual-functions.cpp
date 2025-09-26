#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age = 0;

public:
    virtual ~Person() = default;

    virtual void putdata() {
    }

    virtual void getdata() {
    }
};


class Student final : Person {
    int marks[6] = {};
    int cur_id = 0;

public:
    void getdata() override {
        cin >> name >> age;
        for (int &mark: marks) {
            cin >> mark;
        }
    }

    void putdata() override {
        cout << cur_id;
    }
};

class Professor final : Person {
    int publications = 0;

public:
    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications;
    }
};


int main() {
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[n];

    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        } else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.
    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
