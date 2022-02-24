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
    
    void split(ListNode* source,ListNode** front,ListNode** end){
        
        ListNode* slow =  source;
        ListNode* fast = source->next;
        
        if(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        *front = source;
        *end = slow->next;
        slow->next=NULL;
        
    }
    
    
    ListNode* merge(ListNode* &a,ListNode* &b){
        
        ListNode* res;
        
        if(a==NULL){
            return b;
        }else if(b==NULL){
            return a;
        }
        
        if(a->val<=b->val){
            res = a;
            res->next = merge(a->next,b);
        }else{
            res = b;
            res->next = merge(a,b->next);
        }
        
        return res;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        ListNode* a;
        ListNode* b;
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        split(head,&a,&b);
        a = sortList(a);
        b = sortList(b);
        
        ListNode* q = merge(a,b);
        return q;
    }
};