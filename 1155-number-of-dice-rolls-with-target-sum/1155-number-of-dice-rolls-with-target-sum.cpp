class Solution {
public:
    int mod = 1000000007;
    int solve(int d,int f,int t,vector<vector<int>> &dp){
        
        if(d==0 && t==0){
            return 1;
        }
        
        if(d<=0 || t<=0){
            return 0;
        }
        
        if(dp[d][t]!=-1){
            return dp[d][t];
        }
        
        int count  = 0;
        for(int i=1;i<=f;i++){
            count = ((count%mod) + (solve(d-1,f,t-i,dp)%mod))%mod;
        }
        
        return dp[d][t] = count%mod;
        
    }
    
    int numRollsToTarget(int d, int f, int t) {
        
        vector<vector<int>> dp(32,vector<int>(1002,-1));
        return solve(d,f,t,dp)%mod;
        
    }
};