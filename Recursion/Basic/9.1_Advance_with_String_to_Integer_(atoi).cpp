
#include <cctype>   // for isdigit
#include <climits>  // for INT_MAX, INT_MIN
#include <iostream>
using namespace std;

int printAtoi(string str,int start , int result){
    
    if(start == str.length()){
        return result;
    }
    int digit = str[start] - '0';
     result = result * 10 + digit;
    return printAtoi(str,start+1,result);
    
}

 




int main() {
    
    string str = "1234";
    int result = 0;
  
      cout<<printAtoi(str,0,result);
    return 0;
}