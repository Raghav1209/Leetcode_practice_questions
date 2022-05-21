class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        
        int dp[amount+1];
        dp[0] = 0;
        
        for(int i=1;i<=amount;i++){
            dp[i] = INT_MAX;
        }
        
        for(int i=0;i<=amount;i++){
            int res = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    res = dp[i-coins[j]];
                    if(res!=INT_MAX){
                        dp[i] = min(dp[i],res+1);
                    }
                }
            }
        }
        
        if(dp[amount]!=INT_MAX){
            return dp[amount];
        }else{
            return -1;
        }
        
    }
};