#include <iostream>
using namespace std;

class Student
{
public:

    string name;
    int age;

    void display()
    {
        cout << name << endl;
        cout << age << endl;
    }
};

int main()
{

    // new Student() creates object in Heap Memory

    Student* s = new Student();

    // s stores address of object

    s->name = "Laksh";
    s->age = 24;

    s->display();

    // same as

    (*s).display();

    delete s;

}