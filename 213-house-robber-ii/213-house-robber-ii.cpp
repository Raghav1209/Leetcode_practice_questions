class Solution {
public:
    
    int solve(vector<int> nums,int idx,int n,vector<int> &dp){
        if(idx>n){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int not_take = solve(nums,idx+1,n,dp);
        int take = nums[idx]+solve(nums,idx+2,n,dp);
        
        return dp[idx] = max(take,not_take);
        
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==1){
            return nums[0];
        }
        
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        
        return max(solve(nums,0,nums.size()-2,dp1),solve(nums,1,nums.size()-1,dp2));
        
    }
};