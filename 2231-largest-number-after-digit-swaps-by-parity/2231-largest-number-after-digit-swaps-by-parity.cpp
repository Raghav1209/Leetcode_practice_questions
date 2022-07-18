class Solution {
public:
    
    bool isSafe(string s,int i,int l){
        if((s[i]%2==0 && s[l]%2==0) || (s[i]%2==1 && s[l]%2==1)){
            if(s[i]>s[l]){
                return true;
            }
        }
        return false;
    }
    
    void permute(string s,int l,string &ans){
        if(l==s.size()-1){
            if(s>ans){
                ans = s;
            }
            return;
        }
        
        for(int i=l+1;i<s.size();i++){
            if(isSafe(s,i,l)){
                swap(s[i],s[l]);
                permute(s,l+1,ans);
                swap(s[i],s[l]);
            }
        }
        
        permute(s,l+1,ans);
    }
    
    int largestInteger(int num) {
        
        string s = to_string(num);
        
        int n = s.size();
        string ans = s;
        permute(s,0,ans);
        
        return stoi(ans);
        
    }
};