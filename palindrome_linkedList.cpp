 
class Solution {
public:
    
    struct ListNode* reverse_linked_list(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(head != NULL){
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
    }
    
    bool isPalindrome(struct ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        struct ListNode* s = head;
        struct ListNode* f = head;
    
        while((f->next != NULL)&&(f->next->next != NULL)){
            s = s->next;
            f = f->next->next;
        }
        s->next = reverse_linked_list(s->next);
        s = s->next;
        
        while(s != NULL){
            if(head->val != s->val){
                return false;
            }
            head = head->next;
            s = s->next;
        }
        return true;
    }
};