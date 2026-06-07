
// A popular interview solution is:

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};


// Optimal Solution - 2

class Solution { 
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        int lenA = 0;
        int lenB = 0;
        while(tempA != NULL){
            lenA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            lenB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(lenA>lenB){
          int diff = lenA-lenB;
          for(int i=1;i<=diff;i++){
            tempA = tempA->next;
          }
          while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
          }
          return tempA;
        }

         else{
          int diff = lenB-lenA;
          for(int i=1;i<=diff;i++){
            tempB = tempB->next;
          }
          while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
          }
          return tempA;
         }
    }
};

// Not optimal but map Approach 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;

        while(headA){
            st.insert(headA);
            headA = headA->next;
        }

        while(headB){
            if(st.find(headB) != st.end()){
                return headB;
            }

            headB = headB->next;
        }

        return NULL;
    }
};
