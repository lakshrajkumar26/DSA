#include <iostream>
using namespace std;

class Student
{

public:

    Student()
    {
        cout<<"Constructor\n";
    }

    // Destructor
    // Runs automatically when object dies

    Student()
    {
        cout<<"Destructor\n";
    }

};

int main()
{

    Student s;

}