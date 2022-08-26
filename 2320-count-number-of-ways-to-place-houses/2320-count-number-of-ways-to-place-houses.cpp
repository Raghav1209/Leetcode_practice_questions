class Solution {
public:
    long long solve(int n,vector<long long> &dp){
        
        
        if(n==0){
            return 2;
        }
        
        if(n==1){
            return 3;
        }
        
        if(n<0){
            return 0;
        }
        
        if(dp[n-1]!=-1){
            return dp[n-1];
        }
        
        
        int not_take = solve(n-1,dp);
        
        int take = solve(n-2,dp); 
        
        return dp[n-1] = (not_take+take)%1000000007;
        
    
    }
    
    int countHousePlacements(int n) {
        
        vector<long long> dp(n,-1);
        long long x = solve(n-1,dp);
        return (x*x)%1000000007;
    }
};