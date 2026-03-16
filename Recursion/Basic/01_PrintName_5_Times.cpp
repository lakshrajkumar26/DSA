#include <iostream>
using namespace std;



void printName(int count){

    if(count == 5)
        return;
    
    cout<<"Laksh"<<endl;
    printName(count+1);
}

int main() {
    cout << "Hello World"<<endl;
    printName(0);
    return 0;
}