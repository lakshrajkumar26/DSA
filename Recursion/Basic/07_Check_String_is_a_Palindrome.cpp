// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// always remember when  function return type then use return to call resursion 
// only in void no need 
bool checkPalindrome(string s,int start ,int end ){

    if(start >= end) { 
        return true;
    }
    if(s[start] != s[end]){
        return false;
    }
    
 return checkPalindrome(s,start+1,end-1);
}


int main() {
    string s = "lakal";
    int n = s.length();
    
    if(checkPalindrome(s,0,n-1)){
        cout<<"is a Palindrome";
    }
    else{
        cout<<"is not a Palindrome";
    }

    return 0;
}