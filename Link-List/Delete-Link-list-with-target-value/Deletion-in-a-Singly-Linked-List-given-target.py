#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Print Linked List
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL";
}





// Your function
ListNode* deleteValue(ListNode* head, int target) {

    // Write your code here
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while( curr != NULL ){
        
      //when first element 
     if(curr->val == target && prev == NULL){
         next = curr->next;  //stored
         head=next;
         delete curr;
         curr = next;
       }


 
       else if(curr->val == target){
         next = curr->next;  //stored
         prev->next = next;
        
         delete curr;
         curr = next;
       }

      else {
         prev=curr;
       curr= curr->next;
      }
    }
    return head;

};





// Driver
int main() {

    // Creating Linked List
    // 1 -> 2 -> 3 -> 4 -> 3 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    int target;
    cout << "\n\nEnter value to delete: ";
    cin >> target;

    head = deleteValue(head, target);

    cout << "\nAfter Deletion:\n";
    printList(head);

    return 0;
}