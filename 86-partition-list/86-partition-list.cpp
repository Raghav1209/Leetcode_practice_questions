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
        ListNode* curr = head;
        ListNode* nextNode = head;
        ListNode* prev = NULL;
        
        while(nextNode){
            nextNode = nextNode->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
        
    }
    
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* res1 = NULL;
        ListNode* res2 = NULL;
        
        ListNode* p = head;
        
        while(p){
            if(p->val<x){
                ListNode* node = new ListNode(p->val);
                node->next = res1;
                res1 = node;
            }else{
                ListNode* node = new ListNode(p->val);
                node->next = res2;
                res2 = node;
            }
            p = p->next;
        }
        
        if(res1)
            res1 = reverse(res1);
        
        if(res2)
            res2 = reverse(res2);
        
        if(res1){
            p = res1;
        }else{
            return res2;
        }
        
        
        while(p->next){
            p = p->next;
        }
        
        p->next = res2;
        return res1;
        
    }
};