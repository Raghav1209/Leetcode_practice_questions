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
    
    bool solve(TreeNode* root,int target,int sum){
        
        if(root==NULL){
            return false;
        }
        
        sum += root->val;
        
        if(sum==target && (root->left==NULL && root->right==NULL)){
            return true;
        }
        
        // if(sum>target){
        //     return false;
        // }
        
        if(solve(root->left,target,sum)){
            return true;
        }
        if(solve(root->right,target,sum)){
            return true;
        }
        return false;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){
            return false;
        }
        
        int sum = 0;
        
        if(solve(root,targetSum,sum)){
            return true;
        }else{
            return false;
        }
        
    }
};