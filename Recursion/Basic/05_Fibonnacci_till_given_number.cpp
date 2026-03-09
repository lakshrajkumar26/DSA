// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
                     // 2      3     10
 void printFibonacci(int a , int b , int n){
     
     if(n<1){
         return;
     }
     cout<<a<<" "<<endl;
        // next    3 ,2+3=5 , 9
     printFibonacci(b,a+b,n-1);
 }

int main() {
    // Write C++ code here
    
    printFibonacci(2,3,10);

    return 0;
}