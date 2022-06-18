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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextnode = head;
        
        while(nextnode){
            nextnode = nextnode->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum;
        ListNode* res = NULL;
        int carry = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        
        while(p && q){
            
            sum = p->val+q->val+carry;
            
            if(sum>=10){
                carry = sum/10;
                ListNode* node = new ListNode(sum%10);
                node->next = res;
                res = node;
            }else{
                ListNode* node = new ListNode(sum);
                node->next = res;
                res=node;
                carry = 0;
            }
            p=p->next;
            q=q->next;
        }
        
        while(p){
            sum = p->val+carry;
            if(sum>=10){
                carry = sum/10;
                ListNode* node = new ListNode(sum%10);
                node->next = res;
                res = node;
            }else{
                ListNode* node = new ListNode(sum);
                node->next = res;
                res=node;
                carry = 0;
            }
            p=p->next;
        }
        
        while(q){
            sum = q->val+carry;
            if(sum>=10){
                carry = sum/10;
                ListNode* node = new ListNode(sum%10);
                node->next = res;
                res = node;
            }else{
                ListNode* node = new ListNode(sum);
                node->next = res;
                res=node;
                carry = 0;
            }
            q=q->next;
        }
        
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = res;
            res = node;
        }
        res = reverse(res);
        return res;
        
    }
};