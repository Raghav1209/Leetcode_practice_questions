class Solution {
public:
    
    int solve(vector<int> &nums,int target,vector<int> &dp){
        
        if(target==0){
            return 1;
        }
        
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                count += combinationSum4(nums,target-nums[i]);
            }
        }
        
        return dp[target] = count;
    }
    
    unsigned int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        
        
        dp[target+1];
        dp[0] = 1;
        
        for(int i=1;i<=target;i++){
            int count = 0;
        
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=i){
                    count += dp[i-nums[j]];
                }
            }

            dp[i] = count;
        }
        
        return dp[target];
        
        
        
    }
};