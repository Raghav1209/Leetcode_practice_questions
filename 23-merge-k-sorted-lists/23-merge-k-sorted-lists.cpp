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
    
     ListNode* reverse(ListNode* head)
    {
        // Initialize current, previous and
        // next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
  
        while (current != NULL) {
            // Store next
            next = current->next;
  
            // Reverse current node's pointer
            current->next = prev;
  
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
         return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int n = lists.size();
        
        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size()==1){
            return lists[0];
        }
        
        
        
        ListNode* temp=NULL;
        ListNode* rev;
        while(lists.size()!=1){
            ListNode* p = lists[0];
            ListNode* q = lists[1];
            // temp = NULL;
            while(p && q){
                if(p->val<=q->val){
                    ListNode* node = new ListNode(p->val);
                    node->next = temp;
                    temp = node;
                    p=p->next;
                }else {
                    ListNode* node = new ListNode(q->val);
                    node->next = temp;
                    temp = node;
                    q = q->next;
                }
            }
            
            while(p){
                ListNode* node = new ListNode(p->val);
                node->next = temp;
                temp = node;
                p=p->next;
            }
            
            while(q){
                ListNode* node = new ListNode(q->val);
                node->next = temp;
                temp = node;
                q=q->next;
            }
            
            rev = reverse(temp);
            
            lists.push_back(rev);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            temp = NULL;
        }
        
        return lists[0];
    }
};