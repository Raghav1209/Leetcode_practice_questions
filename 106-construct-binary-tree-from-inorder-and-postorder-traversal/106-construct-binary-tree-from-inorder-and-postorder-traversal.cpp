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
    int postIndex;
    TreeNode* solve(vector<int> &inorder,vector<int> &postorder,int is,int ie){
        
        if(ie<is){
            return NULL;
        }
        
        
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        
        int inIndex;
        
        for(int i=0;i<=ie;i++){
            if(inorder[i]==root->val){
                inIndex = i;
                break;
            }
        }
        
        root->right = solve(inorder,postorder,inIndex+1,ie);
        root->left = solve(inorder,postorder,is,inIndex-1);
        
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int is = 0;
        int ie = postorder.size()-1;
        postIndex = postorder.size()-1;
        TreeNode* root = solve(inorder,postorder,is,ie);
        
        return root;
        
    }
};