// Online C++ compiler to run C++ program online
#include <iostream>
#include <cctype>   // for isdigit
#include <climits>  // for INT_MAX, INT_MIN
using namespace std;

// int printAtoi(string str,int start , int result){
    
int printAtoi(const string &str,int start , long result, int sign){
    
  
    //  if(start == str.length()){
         
    //  }
    
    if(start == str.length() || !isdigit(str[start])){
        return result * sign;
       
    }
    int digit = str[start] - '0';
     result = result * 10 + digit;
     
     if(result* sign > INT_MAX){
         return INT_MAX;
     }
     if(result * sign < INT_MIN){
         return INT_MIN;
     }
     
    return printAtoi(str,start+1,result, sign);
    
}






int main() {
    
    string str = "    -04567as";
    int start =0;
    int result = 0;
    int sign = 1;
     // checking space
     while(start < str.length() && str[start] == ' ')
         start++;
         
          
    
   
    //checking sign  also start < str.length() && this for outbound (IMP)
    if(start < str.length() && str[start] == '-' || str[start] == '+' ){
        
        if(str[start] == '-'){
            sign = -1;
        }
        start++;
    }
    
    
  
      cout<<printAtoi(str,start,result,sign);
    return 0;
}