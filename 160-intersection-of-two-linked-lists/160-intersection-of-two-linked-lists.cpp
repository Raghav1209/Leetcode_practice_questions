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
        
        int countA = 0;
        int countB = 0;
        
        ListNode* p = headA;
        ListNode* q = headB;
        
        while(p){
            countA++;
            p=p->next;
        }
        
        while(q){
            countB++;
            q=q->next;
        }
        p = headA;
        q = headB;
        int diff = abs(countA-countB);
        int i = 0;
        if(countA>countB){
            while(i<diff){
                p=p->next;
                i++;
            }
        }else{
            while(i<diff){
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