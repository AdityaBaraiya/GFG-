//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *findMid(struct Node* head){
        struct Node *slow=head;
        struct Node *fast=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
      Node * merge(struct Node * left,struct Node * right){
        if(!left) return right;
        if(!right) return left;
        
        Node * cur = NULL,*res = NULL;
        
        if(left->data <= right ->data){
            cur = res = left;
            left = left->next;
        }else{
            cur = res = right;
            right = right->next;
        }
        
        while(left && right){
            if(left -> data < right -> data){
                cur->next = left;
                left->prev = cur;
                cur = left;
                left = left->next; 
            }else{
                cur->next = right;
                right->prev = cur;
                cur = right;
                right = right->next; 
            }
        }
        
        if(left){
            cur ->next = left;
            left->prev = cur;
        }
        if(right){
            cur ->next = right;
            right->prev = cur;
        }
        
        return res;
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        
        struct Node * middle=findMid(head);
        struct Node *first=head;
        
        
        struct Node * second=middle->next;
        middle->next=second->prev=NULL;
        
         first=sortDoubly(first);
          second =sortDoubly(second);
        return merge(first,second);
    }
};

//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends