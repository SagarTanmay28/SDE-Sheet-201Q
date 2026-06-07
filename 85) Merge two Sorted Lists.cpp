class Solution {
public:   // O(1)
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
       ListNode* c = new ListNode(-1);
       ListNode* temp = c;
       while(a!=NULL && b!=NULL){
        if(a->val <= b->val){
            temp->next = a;
            a = a->next;
            temp = temp->next;
        }
        else{
            temp->next = b;
            b = b->next;
            temp = temp->next;
        }
       }
       if(a==NULL) temp->next = b;
       else temp->next = a;
       return c->next;
    }
};
