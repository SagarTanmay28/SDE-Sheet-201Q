
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        // 1 2
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* a = slow;
        ListNode* b = slow->next;
        b = reverseList(b);
        a->next = b;
        a = head;
        while(b){
          if(a->val != b->val) return false;
          a = a->next;
          b = b->next;
        }
        return true;
    }
};
