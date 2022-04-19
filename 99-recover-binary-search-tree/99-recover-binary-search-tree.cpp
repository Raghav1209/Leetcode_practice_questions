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
    
    void inorder(TreeNode* root,vector<int> &v){
        if(root!=NULL){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    
    void solve(TreeNode* root,vector<int> &v){
        
        if(root!=NULL){
            solve(root->left,v);
            if(prev!=NULL && prev->val>root->val){
                if(first==NULL){
                    first = prev;
                }
                second = root;
            }
            prev = root;
            solve(root->right,v);
        }
        
    }
    
    TreeNode *first=NULL,*second=NULL;
    TreeNode* prev = NULL;
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        solve(root,v);
        swap(first->val,second->val);
    }
};