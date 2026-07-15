#include <iostream>
using namespace std;

class Student
{

public:

    int age;

    void setAge(int age)
    {
        // this points to current object

        this->age = age;
    }

};

int main()
{

    Student s;

    s.setAge(24);

    cout<<s.age;

}