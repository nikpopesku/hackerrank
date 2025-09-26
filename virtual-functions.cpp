#include <iostream>
using namespace std;

class Person {
    string name;
    int age = 0;

    virtual void putdata() {

    }

    virtual string getdata() {}
};


class Student: Person {
    int marks[1000] = {};

    void getdata() override {
    }
};

class Professor: Person {
    int publications[1000];

public:
    int publications() {
        return 4;
    }

    static int cur_id() {
        return 5;
    }

    void getdata() {

    }
};



int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
