// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;


void printSub(int arr[],vector<int>&ans,int n , int index){
    
    if(index ==n){
        for(int ele : ans){
            cout<<ele<<" ";
        }
        cout<<endl;
        return;
    }
     
     ans.push_back(arr[index]);  //before  recursion calling 
     
    printSub(arr,ans,n,index+1);   // after calling now backtracking 
    
    ans.pop_back();   
    
     printSub(arr,ans,n,index+1);
    
    
    
    
}

int main() {
    // Write C++ code here
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>ans;
    printSub(arr,ans,n,0);
    
    cout << "end of recursion calls";

    return 0;
}