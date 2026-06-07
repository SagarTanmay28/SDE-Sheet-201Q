class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        bool flag = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
              flag = true;
              break; // Importance of Break
            } 
        }
        if(flag==false) return NULL;
        
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};
