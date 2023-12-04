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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* prev = NULL, *curr = slow;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            curr->next = prev;
            prev = curr;
            curr = slow;
        }
        int res = 0;
        while (slow) {
            res = max(res, slow->val + prev->val);
            slow = slow->next, prev = prev->next;
        }
        return res;
    }
};

int main() {
    
    return 0;
}