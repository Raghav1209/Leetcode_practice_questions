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
    
    TreeNode* search(TreeNode* root,int val){
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        
        if(root->val>val){
            TreeNode* x = search(root->left,val);
            return x;
        }else{
             TreeNode* y = search(root->right,val);
            return y;
        }
        
       
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* res =  search(root,val);
        
        
        return res;
        
    }
};