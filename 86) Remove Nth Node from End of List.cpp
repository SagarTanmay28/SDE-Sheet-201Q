class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;

        ListNode* temp = head;
        while(temp != NULL){
            m++;
            temp = temp->next;
        }

        if(n == m) return head->next;

        temp = head;
        for(int i=1;i<=m-n-1;i++) temp = temp->next;

        temp->next = temp->next->next;

        return head;
    }
};
