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
    
    TreeNode* solve(vector<int> &preorder,vector<int> &inorder,int is,int ie){
        
        if(is>ie){
            return NULL;
        }
        
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        int inIndex;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==node->val){
                inIndex = i;
                break;
            }
        }
        
        node->left = solve(preorder,inorder,is,inIndex-1);
        node->right = solve(preorder,inorder,inIndex+1,ie);
        return node;
        
    }
    
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int is=0;
        int ie=preorder.size()-1;
        return solve(preorder,inorder,is,ie);
        
    }
};