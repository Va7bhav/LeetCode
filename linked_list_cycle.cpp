#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* f = head;
        ListNode* s = head;

        while((f!=s) && (f!=NULL)){
            s = s->next;
            f = f->next->next;
        }
        if(f==s){
            return true;
        }
        return false;
    }
};
int main() {
    
    return 0;
}