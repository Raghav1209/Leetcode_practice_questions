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

    
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int start;
        int end;
        int res =1;
        
        while(!q.empty()){
            
            start = q.front().second;
            end = q.back().second;
            res = max(res,end-start+1);
            
            int n = q.size();
            for(int i=0;i<n;i++){
                
                pair<TreeNode*,int> curr = q.front();
                q.pop();
                int index = curr.second-start;
                
                if(curr.first->left){
                    q.push({curr.first->left,(long long)2*index});
                }
                
                if(curr.first->right){
                    q.push({curr.first->right,(long long)2*index+1});
                }
                
            }
            
        }
        
        return res;
        
    }
};