#include <iostream>
using namespace std;

//======================================================
//                C++ OOPS COMPLETE NOTES
//======================================================

// OOPS = Object Oriented Programming
// Think of a Class as a Blueprint
// Think of an Object as the Real Thing created from the Blueprint

// Example:
//
// Blueprint ---> House
//
// Class -----> Object
//
// One class can create many objects.

//======================================================
//                     CLASS
//======================================================

class Student
{
public:

    // Data Members (Variables)

    string name;
    int age;

    // Member Function

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }

};

int main()
{

    cout << "========== CLASS & OBJECT ==========\n\n";

    // Object created in Stack Memory

    Student s1;

     

    s1.name = "Laksh";
    s1.age = 24;

    s1.display();

    cout << endl;

    //---------------------------------------------------
    // Another Object
    //---------------------------------------------------

    Student s2;

    s2.name = "Rahul";
    s2.age = 20;

    s2.display();

}