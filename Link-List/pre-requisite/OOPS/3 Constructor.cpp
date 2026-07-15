#include <iostream>
using namespace std;

class Student
{

public:

    string name;

    // Constructor
    // Automatically runs whenever object is created
  

    Student()
    {
        cout << "Constructor Called\n";

        name = "Default Name";
    }

};



 // So constructors are used to give objects an initial state.

//  class Student
// {
// public:
//     string name;
// };

// Student s;

//then if print s.name then nothig comes right ? 

int main()
{

    Student s;

    cout << s.name;

}