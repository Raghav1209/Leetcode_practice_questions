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
    bool isPalindrome(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr = head;
        ListNode* nextnode = head;
        ListNode* prev = NULL;
        
        while(nextnode!=slow){
            nextnode = nextnode->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        
        if(fast){
            slow=slow->next;
        }
        
        while(prev && slow){
            if(prev->val!=slow->val){
                return false;
            }
            prev=prev->next;
            slow=slow->next;
        }
        
        return true;
        
    }
};