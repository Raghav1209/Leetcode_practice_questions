class Solution {
public:
    
    int solve(vector<int> &nums,int i,vector<int> &dp){
        
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int x = 0 + solve(nums,i+1,dp);
        int y = nums[i] + solve(nums,i+2,dp);
        
        return dp[i] = max(x,y);
        
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        
        return solve(nums,0,dp);
    }
};