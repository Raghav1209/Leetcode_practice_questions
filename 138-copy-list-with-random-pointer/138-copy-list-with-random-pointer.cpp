/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL){
            return NULL;
        }
        
        Node* p = head;
        while(p){
            Node* node = new Node(p->val);
            node->next = p->next;
            p->next = node;
            p=node->next;
        }
       
        p = head;
        Node* q = p->next;
        Node* new_head = head->next;
        
        while(p){
            if(p->random){
                 p->next->random = p->random->next;
            }else{
                p->next->random = NULL;
            }
            
           p=p->next->next;
            if(p==NULL){
                break;
            }
            // q=q->next->next;
           
        }
        p=head;
        q = head->next;
        while(p){
            p->next = q->next;
            p=p->next;
            if(!p){
                break;
            }           
            q->next=p->next;
                q=q->next;
        }
        
       
        
        return new_head;
        
        // return head;
        
    }
};