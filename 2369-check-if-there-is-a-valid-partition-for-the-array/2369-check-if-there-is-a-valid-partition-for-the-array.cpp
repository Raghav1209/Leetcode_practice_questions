class Solution {
public:
    
    bool solve(vector<int> &nums,int i,vector<int> &dp){
        
        if(i==nums.size()){
            return true;
        }
        
        if(i==nums.size()-1){
            return false;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        if(i+2<=nums.size() && nums[i]==nums[i+1] && solve(nums,i+2,dp)){
            return dp[i] = true;
        }else if(i+3<=nums.size() && nums[i]==nums[i+1] && nums[i+1]==nums[i+2] && solve(nums,i+3,dp)){
            return dp[i] = true;
        }else if(i+3<=nums.size() && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1 && solve(nums,i+3,dp)){
            return dp[i] = true;
        }else{
            return dp[i] = false;
        }
        
    }
    
    bool validPartition(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        
        return solve(nums,0,dp);
        
    }
};