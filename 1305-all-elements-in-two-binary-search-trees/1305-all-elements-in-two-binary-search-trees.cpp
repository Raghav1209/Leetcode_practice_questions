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
    
    void getelements(TreeNode* root,vector<int> &ans){
        
        if(root!=NULL){
            ans.push_back(root->val);
            getelements(root->left,ans);
            getelements(root->right,ans);
        }
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        // vector<int> v;
         if(root1==NULL && root2==NULL){
             return ans;
        }
    
        getelements(root1,ans);
        getelements(root2,ans);
        sort(ans.begin(),ans.end());
        // for(auto x : ans){
        //     cout<<x<<" ";
        // }
        return ans;
    }
};