class Solution {
public:
    
    void preorder(TreeNode* root){
        
        if(root==NULL){
            return;
        }
        
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL){
            int count = 0;
            
            for(auto it : mp){
                if(it.second%2!=0){
                    count++;
                }
            }
            
            if(count<=1){
                ans++;
            }
            
            // mp[root->val]--;
            // return;
            
        }
        
        if(root->left){
            preorder(root->left);
        }
        
        if(root->right){
            preorder(root->right);
        }
        mp[root->val]--;
        
    }
    
    int ans = 0;
    unordered_map<int,int> mp;
    int pseudoPalindromicPaths (TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        
        
        preorder(root);
        
        return ans;
        
    }
};