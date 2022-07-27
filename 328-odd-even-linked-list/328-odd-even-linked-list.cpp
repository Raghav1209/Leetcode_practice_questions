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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_list = head->next;
        
        while(odd || even){
            if(even->next){
                odd->next = even->next;
                odd = odd->next;
            }else{
                odd->next = even->next;
                break;
            }
            
            if(odd->next){
                even->next = odd->next;
                even = even->next;
            }else{
                even->next = odd->next;
                break;
            }
            
        }
    
        odd->next = even_list;
        
        return head;
       
        
    }
};