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
        
        if(nums.size()==1){
            return nums[0];
        }
        
        vector<int> dp(nums.size());
        
        dp[nums.size()-1] = nums[nums.size()-1];
        dp[nums.size()-2] = max(nums[nums.size()-1],nums[nums.size()-2]);
        
        for(int i=nums.size()-3;i>=0;i--){
            
            int x = dp[i+1];
            int y = nums[i] + dp[i+2];
        
            dp[i] = max(x,y);
        
        }
        
        
        
        return dp[0];
    }
};