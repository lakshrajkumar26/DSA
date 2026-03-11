// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool isSorted(const int arr[],int n,int idx){
    if(idx == n-1) return true;
    
    if(arr[idx] > arr[idx+1]){
        return false;
    }
    
    return isSorted(arr,n,idx+1);
    
}

int main() {
    // Write C++ code here
  int arr[] = {1,2,3,4,5};
  int n = 5;
  int idx =0;
  
  cout<<isSorted(arr,n,idx);

    return 0;
}