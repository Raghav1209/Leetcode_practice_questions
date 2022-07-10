/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
       if(node==NULL){
           return NULL;
       } 
        
       unordered_map<Node*,Node*> vis;
        queue<Node*> q;
        Node* clone = new Node(node->val);
       vis[node] = clone;
        q.push(node);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for(auto nei : curr->neighbors){
                if(!vis[nei]){
                    vis[nei] = new Node(nei->val);
                    q.push(nei);
                }
                vis[curr]->neighbors.push_back(vis[nei]);
            }
            
        }
        
        return vis[node];
        
        
    }
};