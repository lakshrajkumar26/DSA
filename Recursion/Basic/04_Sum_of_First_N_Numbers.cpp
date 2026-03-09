#include <iostream>
using namespace std;

void printSum(int i,int n,int sum){

if(i>n){
cout<<sum;
return;
}
  
    
    printSum(i+1,n,sum+i);
    

}
int main() {
    cout << "Starting main Function"<<endl;
    printSum(1,10,0);
    return 0;
}