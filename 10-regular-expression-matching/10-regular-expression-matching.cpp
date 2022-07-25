class Solution {
public:
    
    bool func(string s,string p,int i,int j,vector<vector<int>> &dp){
        
        if(j==p.size()){
            return i==s.size();
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool first_match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        int ans = 0;
        
        if(j+1<p.size()  && p[j+1]=='*'){
            ans = (first_match && func(s,p,i+1,j,dp)) || func(s,p,i,j+2,dp);
        }else{
            ans = first_match && func(s,p,i+1,j+1,dp);
        }
        
        return dp[i][j] = ans;
        
    }
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return func(s,p,0,0,dp);
        
    }
};