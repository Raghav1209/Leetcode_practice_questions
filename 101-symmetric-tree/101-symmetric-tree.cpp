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
    
    bool solve(TreeNode* p,TreeNode* q){
        
        if(!p && !q){
            return true;
        }
        
        if((p==NULL && q!=NULL) || (q==NULL && p!=NULL)){
            return false;
        }
        
        return p->val==q->val && solve(p->right,q->left) && solve(p->left,q->right);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        
        return solve(p,q);
        
    }
};