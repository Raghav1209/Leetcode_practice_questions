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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* p = headA;
        ListNode* q = headB;
        int countA,countB;
        countA = countB = 0;

        while(p!=NULL){
            countA++;
            p=p->next;
        }
        
        while(q!=NULL){
            countB++;
            q=q->next;
        }
        
        int diff = abs(countA-countB);
        int i=0;
        p=headA;
        q=headB;
        if(countA>countB){
            while(i!=diff){
                p=p->next;
                i++;
            }
        }else{
            while(i!=diff){
                q=q->next;
                i++;
            }
        }
        
        while(p!=q){
            p=p->next;
            q=q->next;
        }
        
        return p;
        
    }
};