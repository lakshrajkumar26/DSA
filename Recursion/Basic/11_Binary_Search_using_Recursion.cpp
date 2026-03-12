// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

bool binarySearch(int arr[], int key , int start , int end){
    
    int mid = (start+end)-start/2;
    
    if(start<=end){
        
        if(arr[mid] == key){
            return true;
        }
        else if(arr[mid] >key){
            end = mid-1;
           return  binarySearch(arr, key,start,end);
        }
        else{
            start = mid+1;
           return  binarySearch(arr, key,start,end);
        }   
    }
    return false;
}



int main() {
    // Write C++ code here
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    int start = 0;
    int end = n-1;
    int key = 3;
    cout<<binarySearch(arr, key,start,end);

    return 0;
}