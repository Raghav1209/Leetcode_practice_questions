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
    
    void preorder(TreeNode* root,int path){
        
        path ^= (1<<root->val);
        
        if(root->left==NULL && root->right==NULL){
            if((path&(path-1)) == 0){
                ans++;
            }
            return;
        }
        
        if(root->left){
            preorder(root->left,path);
        }
        
        if(root->right){
            preorder(root->right,path);
        }
        
    }
    
    int ans = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        preorder(root,0);
        
        return ans;
        
    }
};