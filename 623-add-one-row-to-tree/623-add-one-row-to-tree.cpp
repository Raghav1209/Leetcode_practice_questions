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
    
    
    void solve(TreeNode* &root,int val,int d,int dep){
        
        if(root==NULL){
            return;
        }
        
        if(dep==d-1){
            
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            
            root->left->left = temp;
            
            temp = root->right;
            root->right = new TreeNode(val);
            
            root->right->right = temp;
            return;
            
        }
        
        solve(root->left,val,d,dep+1);
        solve(root->right,val,d,dep+1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
            if(depth==1){
                TreeNode* node = new TreeNode(val);
                
                node->left = root;
                return node;
                
            }
        
            solve(root,val,depth,1);
            return root;
    }
};