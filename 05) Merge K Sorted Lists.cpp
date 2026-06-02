You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

// Heap Solution 

class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // push first node of every list
        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            pq.pop();

            // attach original node
            tail->next = node;
            tail = tail->next;

            // push next node of that list
            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};

// Linked List Solution - 1

class Solution {
public:
      ListNode* merge(ListNode* a, ListNode* b) {
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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size() > 1){
            ListNode* a = arr[arr.size()-1];
            arr.pop_back();
            ListNode* b = arr[arr.size()-1];
            arr.pop_back();
            ListNode* c = merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

// Linked List Solution - 2

class Solution {
public:
    
ListNode* merge(ListNode* a, ListNode* b) {
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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size() > 1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

