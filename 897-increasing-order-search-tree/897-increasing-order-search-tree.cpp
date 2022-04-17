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
    
    void solve(TreeNode* root,TreeNode* dummy){
        
        if(root!=NULL){
            solve(root->left,dummy);
            if(prev==NULL){
                TreeNode* root_node = new TreeNode(root->val);
                dummy->right = root_node;
                prev = root_node;
            }else{
                TreeNode* node = new TreeNode(root->val);
                prev->right = node;
                prev = node;
            }
            // prev = root;
            solve(root->right,dummy);
        }
            
        
        
        
        
        
    }
    TreeNode* prev = NULL;
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* increasingBST(TreeNode* root) {
        
        // TreeNode* new_root = solve(root);
        solve(root,dummy);
        return dummy->right;
        
    }
};