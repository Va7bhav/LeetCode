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
public:
    ListNode* sortList(ListNode* head) { 
        if(!(head) || !(head->next)) return head;
        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* tmp = right->next;
        right->next = NULL;
        right = tmp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1, list2); 
        ListNode* founder = list1;
        ListNode* dummy = founder;
        list1 = list1->next;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            }
            else {
                dummy->next = list2;
                list2 = list2->next;
            }
                dummy = dummy->next;
        }
        if(list1 == NULL) {
            dummy->next = list2;
        }
        else if(list2 == NULL){
            dummy->next = list1;
        }
        return founder;
    }
};



int main() {
    
    return 0;
}