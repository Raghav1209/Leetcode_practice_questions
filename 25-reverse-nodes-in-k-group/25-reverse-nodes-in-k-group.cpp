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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        
        for(int i=1;i<k;i++){
            temp = temp->next;
            if(temp == NULL){
                return head;
            }
        }
        
        ListNode* nextnode = temp->next;
        
        ListNode* curr = head;
        ListNode* p = head;
        ListNode* prev = NULL;
        ListNode* nexn = curr;
        while(nexn!=nextnode){
            nexn = nexn->next;
            curr->next = prev;
            prev = curr;
            curr = nexn;
        }
        
        if(nextnode){
              p->next = reverseKGroup(nextnode,k);
        }
        
        return temp;
       
        
    }
};