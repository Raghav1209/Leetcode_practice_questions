/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        
        vector<int> adj[100001];
        
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        // v.push_back(root->val);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left){
                adj[curr->val].push_back(curr->left->val);
                adj[curr->left->val].push_back(curr->val);
                // v.push_back(curr->left->val);
                q.push(curr->left);
            }
            
            if(curr->right){
                adj[curr->val].push_back(curr->right->val);
                adj[curr->right->val].push_back(curr->val);
                // v.push_back(curr->right->val);
                q.push(curr->right);
            }
            
        }
        
        queue<int> qq;
        vector<bool> vis(100001,false);
        qq.push(start);
        int count = 0;
        
        while(!qq.empty()){
            int n = qq.size();

            
            for(int i=0;i<n;i++){
                int x = qq.front();
                vis[x] = true;
                qq.pop();
                for(int y : adj[x]){
                    if(!vis[y]){
                        qq.push(y);
                    }
                }
            }
            
            if(qq.empty()){
                break;
            }
            
            count++;
        }
        
        return count;
        
        
        
    }
};