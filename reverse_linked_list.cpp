// tortoise method
// https://youtu.be/sGdwSH8RK-o?t=265
#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

struct Node* reverse_linked_list(struct Node* head){
    struct Node* prev = NULL;
    struct Node* curr = head;

    while(head != NULL){
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    
    return prev;
}
int main(){
    struct Node* head =   new Node;
    struct Node* second = new Node;
    struct Node* third =  new Node;
    struct Node* fourth = new Node;
 
    // Link first and second nodes
    head->val = 7;
    head->next = second;
 
    // Link second and third nodes
    second->val = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->val = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->val = 66;
    fourth->next = NULL;
    
    head = reverse_linked_list(head);
    cout<<"head";

    cout<<head->next->val;
    return 0;
}