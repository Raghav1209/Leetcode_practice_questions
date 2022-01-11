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
    
    void sumRootToLeafutil(TreeNode* root,string str,vector<string> &v){
        if(root==NULL){
            return;
        }
            
        if(root->left==NULL && root->right==NULL){
            if(root->val == 0){
            str += '0'-root->val;
        }else{
            str += '0'+root->val;
        }
            // reverse(str.begin(),str.end());
            v.push_back(str);
            str.erase(str.length()-1);
            return;
        }
        
        if(root->val == 0){
            str += '0'-root->val;
        }else{
            str += '0'+root->val;
        }
        sumRootToLeafutil(root->left,str,v);
        // str += root->val;
        sumRootToLeafutil(root->right,str,v);
        str.erase(str.length()-1);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        string str="";
        int sum = 0;
        vector<string> v;
        sumRootToLeafutil(root,str,v);
        
        for(int i=0;i<v.size();i++){
            sum += stoi(v[i],0,2);
        }
        
        return sum;
    }
};