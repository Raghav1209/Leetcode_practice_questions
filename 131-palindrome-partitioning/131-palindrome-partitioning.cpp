class Solution {
public:
    
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string s,vector<string> &v,int index,vector<vector<string>> &ans){
        
        if(index==s.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            
            if(isPalindrome(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                solve(s,v,i+1,ans);
                v.pop_back();
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
       
        vector<vector<string>> ans;
        vector<string> v;
        
        solve(s,v,0,ans);
        
        return ans;
        
    }
};