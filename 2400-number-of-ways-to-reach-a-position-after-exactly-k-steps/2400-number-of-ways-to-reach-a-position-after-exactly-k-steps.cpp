class Solution {
public:
    
    int solve(int startPos,int endPos,int k,vector<vector<int>> &dp){
        
        if(k==0){
            if(startPos==endPos){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[startPos+1000][k]!=-1){
            return dp[startPos+1000][k]%1000000007;
        }
        
        int count = 0;
        
        count += solve(startPos-1,endPos,k-1,dp);
        count += solve(startPos+1,endPos,k-1,dp);
        return dp[startPos+1000][k] = count%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        // map<pair<int,int>,int> dp;
        int c = solve(startPos,endPos,k,dp);
        return c%1000000007;
    }
};