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
        ListNode* nextnode = head;
        ListNode* prev = NULL;
        
        while(nextnode){
            nextnode = nextnode->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        
        return prev;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL){
            return l2;
        }
        
        if(l2==NULL){
            return l1;
        }
        ListNode* res = NULL;
        int carry = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        int sum,x;
        while(p || q){
            
            if(carry){
                if(p && q==NULL){
                    sum = p->val + carry;
                }else if(p==NULL && q){
                    sum = q->val + carry;
                }
                else{
                    sum = p->val + q->val + carry;
                }
            }else{
                if(p==NULL && q){
                    sum = q->val + carry;
                }else if(p && q==NULL){
                    sum = p->val + carry;
                }else{
                    sum = p->val + q->val + carry;
                }
            }
             x = sum % 10;
             carry = sum/10;
            ListNode* node = new ListNode(x);
            node->next = res;
            res = node;
            
            if(p){
                p=p->next;
            }
            
            if(q){
                q=q->next;
            }
        }
        
        // while(p){
        //     if(carry){
        //         sum = p->val  + carry;
        //     }else{
        //         sum = p->val;
        //     }
        //     x = sum % 10;
        //     carry = sum/10;
        //     ListNode* node = new ListNode(x);
        //     node->next = res;
        //     res = node;
        //     p=p->next;
        //     // q=q->next;
        // }
        
        // while(q){
        //     if(carry){
        //         sum =  q->val + carry;
        //     }else{
        //         sum =  q->val;
        //     }
        //      x = sum % 10;
        //      carry = sum/10;
        //     ListNode* node = new ListNode(x);
        //     node->next = res;
        //     res = node;
        //     // p=p->next;
        //     q=q->next;
        // }
        
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = res;
            res = node;
        }
        
        ListNode* req = reverse(res);
        
        return req;
        
    }
};