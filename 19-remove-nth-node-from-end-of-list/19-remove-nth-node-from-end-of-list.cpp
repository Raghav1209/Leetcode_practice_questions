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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* p = head;
        int count = 0;
        
        while(p){
            count++;
            p=p->next;
        }
        
        if(count==1 && n==1){
            return NULL;
        }
        
        if(count==n){
            return head->next;
        }
        
        int diff = count-n;
        
        int i=0;
        p=head;
        while(i<diff-1){
            p=p->next;
            i++;
        }
        
        ListNode* temp = p->next;
        
        p->next = temp->next;
        
        delete(temp);
        
        return head;
        
    }
};