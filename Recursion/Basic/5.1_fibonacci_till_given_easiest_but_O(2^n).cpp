// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

 int fib(int n) {
    
    if(n==0 || n==1){
        return n;
    }
    return fib(n-2) + fib(n-1);
}

int main() {
    // Write C++ code here
   cout<<fib(6);

    return 0;
}