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
    
    int maxpath(TreeNode* root,int &maxx){
        
        if(root==NULL){
            return 0;
        }
        
        int left = max(0,maxpath(root->left,maxx));
        int right = max(0,maxpath(root->right,maxx));
        
        maxx = max(maxx,root->val+left+right);
        
        return root->val+max(left,right);
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        int maxx = INT_MIN;
        int x = maxpath(root,maxx);
        return maxx;
        
    }
};