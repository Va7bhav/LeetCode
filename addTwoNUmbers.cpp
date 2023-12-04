#include<iostream>
#include<cmath>
using namespace std;


   class Solution {
public:

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* founder = new ListNode;
        ListNode* dummy = founder->next;
        while(l1 != NULL || l2 != NULL || carry != NULL) {
            int sum = 0;
            if(l1!=NULL) {
                sum += l1->val;
            }
            if(l2!=NULL) {
                sum += l2->val;
            }
            ListNode* node = new ListNode();
            node->val = (sum + carry)%10;
            dummy->next = node;
            
            dummy = dummy->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        return founder->next;
    }
};

int main() {

    return 0;
}