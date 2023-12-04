// tortoise method
// https://youtu.be/sGdwSH8RK-o?t=265
#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

struct Node* mid_of_list(struct Node* head){
    struct Node* f = head;
    struct Node* s = head;

    while(f->next != NULL && f->next->next != NULL){
        s = s->next;
        f = f->next->next;
        if(f->next == NULL){         // linked list length is odd
            return s;
        }
        if(f->next->next == NULL){   // linked list length is even
            return s->next;
        }
    }
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
    
    struct Node* mid = new Node;
    mid = mid_of_list(head);
    cout<< mid->val;
    
    return 0;
}