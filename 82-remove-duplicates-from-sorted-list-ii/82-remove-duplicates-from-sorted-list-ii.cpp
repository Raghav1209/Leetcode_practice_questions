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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL){
            return head;
        }
        
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* new_prev = prev;
        while(q){
            
            if(p->val != q->val){
                new_prev=p;
                p=p->next;
                q=q->next;
            }else{
                // q=q->next;
                while(q && p->val == q->val){
                    q=q->next;
                    // if(q==NULL){
                    //     break;
                    // }
                }
                while(p!=q){
                    ListNode* temp = p;
                    p=p->next;
                    delete(temp);
                }
                new_prev->next = p;
                if(q==NULL){
                    break;
                }
                q=q->next;
            }
            
        }
        
        return prev->next;
        
    }
};