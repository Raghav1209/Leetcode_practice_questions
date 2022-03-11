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
    ListNode* rotateRight(ListNode* head, int k) {
        
        
        if(head==NULL || k==0){
            return head;
        }
        
        int count = 0;
        // int kk;
        ListNode* p = head;
        
        while(p){
            count++;
            p=p->next;
        }
        
        if(count==1){
            return head;
        }
        
        // if(k==count){
        //     return head;
        // }
        
        if(k>=count){
            k = k%count;
        }
        
        int diff = count-k;
         if(diff==count){
            return head;
        }
        int i = 1;
        p = head;
        while(i!=diff){
            p=p->next;
            i++;
        }
        
        ListNode* new_head = p->next;
        p->next = NULL;
        ListNode* q = new_head;
        while(q->next){
            q=q->next;
        }
        
        q->next = head;
        
        return new_head;
        
    }
};