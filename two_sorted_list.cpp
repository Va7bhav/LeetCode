#include<iostream>
using namespace std;

class Solution {
public:
    struct ListNode{
        int val;
        struct ListNode* next;
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        if(list1->val > list2->val) swap(list1, list2);
        ListNode* founder = list1;
        while(list1 != NULL && list2 != NULL){
            ListNode *temp = NULL;
            while(list1!=NULL && list1->val <= list2->val);
            {
                temp = list1;
                list1 = list1->next;   
            }
            temp->next = list2;
            swap(list1, list2);
        }
    return founder;
    }
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
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
        if(list1 == NULL){
            dummy->next = list2;
        }
        else if(list2 == NULL){
            dummy->next = list1;
        }
        return founder;
    }
};
int main(){
    Solution sally;
    return 0;
}
