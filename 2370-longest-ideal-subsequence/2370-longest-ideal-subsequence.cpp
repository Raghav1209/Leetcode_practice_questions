class Solution {
public:
    
    int solve(string &s,int k,int prev,int idx,vector<vector<int>> &dp){
        
        if(idx>=s.size()){
            return 0;
        }
        
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        
        int maxx = -1;
        int take = 0;
        
        int not_take = solve(s,k,prev,idx+1,dp);
    
        
        if(prev==0 || abs(s[idx]-prev)<=k){
            take = 1+solve(s,k,s[idx],idx+1,dp);
        }
        
        maxx = max(take,not_take);
        
        return dp[idx][prev] = maxx;
        
    }
    
    int longestIdealString(string s, int k) {
        
        int prev = 0;
        vector<vector<int>> dp(s.size()+1,vector<int>(150,-1));
        
        return solve(s,k,prev,0,dp);
    }
};