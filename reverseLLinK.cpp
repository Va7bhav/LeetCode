#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};   

class Solution {
    ListNode* getKth(ListNode* curr, int k) {
        while(k > 0) {
            curr = curr->next;
            k -= 1;
        }
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while(true) {
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) 
                break;
            ListNode* groupNext = kth->next;
    
            // reverse group
            ListNode* curr = groupPrev->next, *prev = kth->next;
            while(curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = groupPrev->next;
            groupNext->next = kth;
            groupPrev = temp;
        }
        return dummy->next;  
    }
};
int main() {
    
    return 0;
}