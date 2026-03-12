// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

void findMinimum(int arr[],int n,int idx,int min){
    
    
    if(idx == n){
        cout<<min<<endl;
        return;
    }
    
    if(arr[idx] < min){
        min = arr[idx];
    }
    findMinimum(arr,n,idx+1,min);
}

void findMaximum(int arr[],int n ,int idx,int max){
    
    if(idx == n ){
     cout<<max<<endl;
     return;
    }
    
    if(arr[idx]>max){
        max = arr[idx];
    }
    findMaximum(arr,n,idx+1,max);
    

}


int main() {
    // Write C++ code here
    int arr[] = {-1, 4, 6, 7, 9, 8, 3, 11,-15,105,21,-21};
    int n = 12;
    int idx = 0;
    int min = INT_MAX;
    int max= INT_MIN;
    
    findMinimum(arr,n,idx,min);
    findMaximum(arr,n,idx,max);
   
    return 0;
}