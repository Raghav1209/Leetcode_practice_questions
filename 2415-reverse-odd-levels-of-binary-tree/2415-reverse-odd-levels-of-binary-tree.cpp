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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        vector<int> values;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(level%2){
                    curr->val = values[size-i-1];
                }
                
                if(curr->left){
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                
                if(curr->right){
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
                
            }
            
            level++;
            values = temp;
            
        }
        
        return root;
        
    }
};