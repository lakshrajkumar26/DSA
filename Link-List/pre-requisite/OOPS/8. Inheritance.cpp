#include <iostream>
using namespace std;

class Animal
{

public:

    void eat()
    {
        cout<<"Animal Eating\n";
    }

};

class Dog : public Animal
{

public:

    void bark()
    {
        cout<<"Dog Barking\n";
    }

};

int main()
{

    Dog d;

    d.eat();

    d.bark();

}