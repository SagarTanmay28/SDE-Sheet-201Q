// Right Middle 

class Solution { // Slow and Fast Pointers  // Most used Question 
public: // This code is for right middle 

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
};
