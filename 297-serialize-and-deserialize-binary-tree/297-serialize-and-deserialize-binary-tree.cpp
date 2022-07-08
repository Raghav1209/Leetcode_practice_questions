/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // vector<int> v;
    string str = "";
    void preorder(TreeNode* root){
        
        if(root==NULL){
            str += " #";
            return;
        }
        
        str += " " + to_string(root->val);
        preorder(root->left);
        preorder(root->right);
        
    }
    
    string serialize(TreeNode* root) {
        
        preorder(root);
        return str;
    }

    TreeNode* solve(istringstream &ss){
        
       
        string val;
        ss >> val;

        if(val=="#"){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(val));
        
        root->left = solve(ss);
        root->right = solve(ss);
        return root;
        
    }
        
        
        
    
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream ss(data);
        return solve(ss);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));