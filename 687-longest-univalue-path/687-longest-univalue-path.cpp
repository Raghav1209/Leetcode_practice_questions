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
    
    int solve(TreeNode* root,int par){
        
        if(root==NULL){
            return 0;
        }
        
        int l = solve(root->left,root->val);
        int r = solve(root->right,root->val);
        
        ans = max(ans,l+r);
        
        if(par==root->val){
            return max(l,r)+1;
        }
        
        return 0;
        
    }
    
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        
        int x = solve(root,INT_MIN);
        return ans;
        
    }
};