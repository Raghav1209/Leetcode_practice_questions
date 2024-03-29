/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head==NULL){
            return false;
        }
        
         ListNode* slow = head;
        ListNode* fast = slow->next;
       
        
        while(slow!=fast){
            slow = slow->next;
            if(fast==NULL || fast->next==NULL){
                return false;
            }
            fast = fast->next->next;
            
        }
        
        return true;
        
        
    }
};