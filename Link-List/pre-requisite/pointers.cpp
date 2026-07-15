// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 
 class Node {
     public:
     int data;
     //as simialr as int* ptr = x; 
     //Node is Type here like int or string
     Node* next;
 };
 
int main() {
    // Write C++ code here
    cout << "start Basic"<<endl;
    
    //creating a new Node() but it give address  so to store the add used Node* first else not able to store 
    Node* first = new Node();
    Node* second = new Node();
    
    first->data = 10;
    (*second).data =29;
    
    first->next = second;
    second->next = NULL;
    
    //first data
    cout<<first->data<<endl;
    //first ptr
    cout<<first->next<<endl;
    //for second linked data
    cout<<first->next->data<<endl;
    //will give error 
    cout<<second->next->data<<endl;


    return 0;
}