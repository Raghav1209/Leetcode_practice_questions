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
    
    ListNode* reverse(ListNode* head){
        // Initialize current, previous and
        // next pointers
        ListNode* current = head;
        ListNode* prev = NULL, *next = NULL;

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
    
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* res = NULL;
        ListNode* curr = head;
        ListNode* nxt = curr->next;
        while(nxt || curr){
            if(nxt){
                ListNode* node1 = new ListNode(nxt->val);
                node1->next = res;
                res=node1;
            }
            
            if(curr){
                 ListNode* node2 = new ListNode(curr->val);
                node2->next = res;
                res=node2;
            }
            
            curr=nxt;
            
            if(nxt==NULL){
                continue;
            }
           
            if(nxt->next){
                nxt = nxt->next->next;
            }else{
                nxt = nxt->next;
                // continue;
            }
            
            curr = curr->next;
        }
        
        ListNode* reqList = reverse(res);
        return reqList;
    }
};