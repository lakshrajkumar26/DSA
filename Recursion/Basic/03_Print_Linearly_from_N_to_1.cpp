#include <iostream>
using namespace std;

void printReverseNumbers(int i,int n){
   
   if(i<n)
   return;
   cout<<i<<endl;
    printReverseNumbers(i-1,n);
}


int main() {
    cout << "Starting main Function"<<endl;
    printReverseNumbers(10,1);
    return 0;
}