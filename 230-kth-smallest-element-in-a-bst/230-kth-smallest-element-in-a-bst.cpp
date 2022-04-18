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
    
    void solve(TreeNode* root,int k){
        
        if(root!=NULL){
            solve(root->left,k);
            count++;
            if(count==k){
                x = root;
                return;
            }
            solve(root->right,k);
        }
        
    }
    
    int count = 0;
    TreeNode* x;
    int kthSmallest(TreeNode* root, int k) {
        
        solve(root,k);
        return x->val;
        // return root->val;
    }
};