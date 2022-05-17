/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* found = NULL;
    void find(TreeNode* root,TreeNode* target){
        if(root!=NULL){
            find(root->left,target);
            if(root->val==target->val){
                found = root;
                return;
            }
            find(root->right,target);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        
        find(cloned,target);
        
        return found;
        
    }
};