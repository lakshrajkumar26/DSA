#include <iostream>
using namespace std;

class Student
{

public:

    string name;
    int age;

    // Constructor with parameters

    Student(string n, int a)
    {
        name = n;
        age = a;
    }

};

int main()
{

    Student s("Laksh",24);

    cout << s.name << endl;
    cout << s.age;

}