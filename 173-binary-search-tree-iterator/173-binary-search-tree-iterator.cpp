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
class BSTIterator {
public:
    vector<int> v;
    int i=-1;
    
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            // cout<<root->val;
            v.push_back(root->val);
            inorder(root->right);
        }
        
    }
    
    BSTIterator(TreeNode* root) {
        
        inorder(root);
        
    }
    
    int next() {
        i++;
        return v[i];
    }
    
    bool hasNext() {
        if(i!=v.size()-1){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */