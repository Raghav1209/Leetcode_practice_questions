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
    
    void solve(TreeNode* root,int sum,vector<int> v,vector<vector<int>> &ans){
        
        if(root==NULL){
            return;
        }
        
        v.push_back(root->val);
        sum -= root->val;
        
        
    
        if(sum==0 && !root->left && !root->right){
            ans.push_back(v);
            return;
        }
                
        
        
       
        solve(root->left,sum,v,ans);
        solve(root->right,sum,v,ans);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(root,sum,v,ans);
        return ans;
    }
};