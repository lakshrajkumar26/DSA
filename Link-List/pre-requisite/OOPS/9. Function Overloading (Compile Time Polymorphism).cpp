#include <iostream>
using namespace std;

class Math
{

public:

    void add(int a,int b)
    {
        cout<<a+b<<endl;
    }

    void add(double a,double b)
    {
        cout<<a+b;
    }

};

int main()
{

    Math m;

    m.add(2,3);

    m.add(2.5,3.4);

}