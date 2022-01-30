/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head)
    {
        // Initialize current, previous and
        // next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            // Store next
            next = current->next;
  
            // Reverse current node's pointer
            current->next = prev;
  
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* reversell;
        int m = k;
        ListNode* res = NULL;
        ListNode* rev = NULL;
        // vector<ListNode*> v;
        while(p!=NULL){
            while(m>0){
                if(p==NULL){
                    break;
                }
                ListNode* node = new ListNode(p->val);
                node->next = rev;
                rev = node;
                p=p->next;
                // if(m==k){
                //     ListNode* temp = rev;
                // }
                m--;
            }
            if(m==0){
                 reversell = reverse(rev);
            }else{
                reversell = rev;
            }
             ListNode* q = reversell;
                while(q->next){
                    q = q->next;
                }
            q->next=res;
            res = reversell;
            m=k;
            rev=NULL;
        }
        
        ListNode* req = reverse(res);
        
        return req;
       
    }
};