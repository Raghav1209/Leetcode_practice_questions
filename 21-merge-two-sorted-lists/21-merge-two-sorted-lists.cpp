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
        ListNode* prev = NULL;
        ListNode* nextnode = head;
        
        while(nextnode){
            nextnode=nextnode->next;
            curr->next = prev;
            prev = curr;
            curr=nextnode;
        }
        
        return prev;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* res = NULL;
        
        while(p && q){
            if(p->val<=q->val){
                ListNode* node = new ListNode(p->val);
                node->next = res;
                res = node;
                p=p->next;
            }else{
                ListNode* node = new ListNode(q->val);
                node->next = res;
                res = node;
                q=q->next;
            }
        }
        
        while(p){
            ListNode* node = new ListNode(p->val);
            node->next = res;
            res = node;
            p=p->next;
        }
        
        while(q){
            ListNode* node = new ListNode(q->val);
            node->next = res;
            res = node; 
            q=q->next;
        }
        
        ListNode* req = reverse(res);
        return req;
        
    }
};