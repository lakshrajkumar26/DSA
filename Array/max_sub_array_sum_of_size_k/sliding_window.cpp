// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

 int maxSubarraySum(int arr[] ,int n , int k ){
     
     int i = 0;
     int j = 0;
     int maxi = INT_MIN;
        int sum = 0;
     while(j<n){
         sum = sum + arr[j];
      
         if(j-i+1 == k){
             maxi = max(maxi,sum);
             sum = sum - arr[i];
             i++;
             j++;
         }
         else{
             j++;
             
         }
     }
     return maxi;
     
 }

int main() {
    // Write C++ code here
   
   int arr[]={100,200,300,400,500};
   int n = 5;
   int k =2;
   
   
   cout<<maxSubarraySum(arr,n,k);
   
   

    return 0;
}