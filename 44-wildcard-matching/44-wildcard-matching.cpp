class Solution {
public:
    
    bool solve(string s,string p,int m,int n,vector<vector<int>> &dp){
        
        
        if(m==0 && n==0){
            return true;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        if(m>0 && n==0){
            return false;
        }
        
        if(m==0 && n>0){
            for(int ii=0;ii<n;ii++){
                if(p[ii]!='*'){
                    return false;
                }
            }
            return true;
        }
        
        if(s[m-1]==p[n-1] || p[n-1]=='?'){
            return dp[m][n] = solve(s,p,m-1,n-1,dp);
        }
        
        if(p[n-1]=='*'){
            return dp[m][n] = solve(s,p,m-1,n,dp) || solve(s,p,m,n-1,dp);
        }
        
        return dp[m][n] = false;
        
    }
    
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        dp[0][0] = 1;
        
        for(int i=0;i<=m;i++){
            dp[i][0] = 0;
        }
        
        for(int i=0;i<=n;i++){
            int flag = 0;
            for(int ii=0;ii<i;ii++){
                if(p[ii]!='*'){
                    flag = 1;
                }
            }
            if(flag){
                dp[0][i] = 0;
            }else{
                dp[0][i] = 1;
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(p[j-1]=='*'){
                   dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                else dp[i][j] = false;
            }
        }
        
        return dp[m][n];
        
    }
};