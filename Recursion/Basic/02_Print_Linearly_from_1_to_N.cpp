#include <iostream>
using namespace std;

void printNumbers(int i,int n){
   
   if(i>n)
   return;
   cout<<i<<endl;
    printNumbers(i+1,n);
}


int main() {
    cout << "Starting main Function"<<endl;
    printNumbers(1,10);
    return 0;
}