#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    
    map<char, int> M;

    M['a'] = 1;
    M['b'] = 2;

    string str = "abc";

    for(char ch : str){
        
        
        if(M.find(ch) != M.end()){

            //to increse  
            M[ch]= M[ch]+5; //with 5 
            M[ch]++;       // with post incremental
            cout<<ch <<" -> " <<M[ch]<<endl;
        }
        else {
            cout<<ch <<" -> "<<"not found!";
        }
    }
    return 0;
}