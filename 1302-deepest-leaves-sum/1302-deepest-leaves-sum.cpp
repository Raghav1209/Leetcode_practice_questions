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
    
//     void deep(TreeNode* root,int level){
//         if(root==NULL){
//             return;
//         }
        
//         if(root->left==NULL && root->right==NULL && level>=maxlevel){
//             if(level==maxlevel){
//                 sum += root->val;
//             }else{
//                 sum = root->val;
//             }
            
//             maxlevel = level;
//             return;
//         }
        
//         deep(root->left,level+1);
//         deep(root->right,level+1);
        
//     }
    
    // int sum = 0;
    // int maxlevel=0;
    int deepestLeavesSum(TreeNode* root) {
      //   int level = 1;
      // deep(root,level);
      //   return sum;
        
        
        // USING QUEUE
        
        queue<TreeNode*> q;
        int count;
        q.push(root);
        int i;
        int sum=0;
        while(!q.empty())
        {
            count=q.size();
            sum=0;
            for(i=0;i<count;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                    
                }
                if(curr->right!=NULL)
                {
                    q.push(curr->right); 
                }
                sum+=curr->val;
            }
        }
        return sum;
        
    }
};