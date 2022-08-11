class Solution {
public:
    
    int solve(string &s,int k,int prev,int n,vector<vector<int>> &dp){
        
        if(n<0){
            return 0;
        }
        
        if(dp[n][prev]!=-1){
            return dp[n][prev];
        }
        
        int maxx = -1;
        int take = 0;
        
        int not_take = solve(s,k,prev,n-1,dp);
    
        
        if(prev==0 || abs(s[n]-prev)<=k){
            take = 1+solve(s,k,s[n],n-1,dp);
        }
        
        maxx = max(take,not_take);
        
        return dp[n][prev] = maxx;
        
    }
    
    int longestIdealString(string s, int k) {
        
        int prev = 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(150,-1));
        
        return solve(s,k,prev,s.size()-1,dp);
    }
};