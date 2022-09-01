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
    
    void solve(TreeNode* root,int maxx){
        
        if(root==NULL){
            return;
        }
        
        
        int m = max(maxx,root->val);
        
        solve(root->left,m);
        
        
        if(root->val>=m){
            count++;
            // cout<<count<<" ";
        }
        
        
        solve(root->right,m);
        
        
    }
    int count = 0;
    int goodNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        // int maxx = INT_MIN;
        solve(root,INT_MIN);
        
        return count;
        
    }
};