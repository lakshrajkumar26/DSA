#include <iostream>
using namespace std;
    //        2      ,  4
int power(int n , int pw){
    
    if(pw==0){
        return 1;
    }
   // why not n=n*n; 
   //always try do find what to call repeatedly with what will will be contant value to make formulae
    return n * power(n,pw-1);
}

int main() {
  int n = 2;
  int pw = 3;
  
    cout<<power(n,pw);
    return 0;
}