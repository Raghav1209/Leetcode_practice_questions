class Solution {
public:
    
    int solve(vector<int> &nums,vector<int> &mul,int l,int h,int i,vector<vector<int>> &dp){
        
        if(i==mul.size()){
            return 0;
        }
        
        // if(l>h){
        //     return 0;
        // }
    
        
        if(dp[l][i]!=INT_MIN){
            return dp[l][i];
        }
        
        
        int sum = 0;
        int left = (nums[l]*mul[i]) + solve(nums,mul,l+1,h,i+1,dp);
        int right = (nums[h-(i-l)]*mul[i]) + solve(nums,mul,l,h,i+1,dp);
        
        return dp[l][i] = max(left,right);
        
        
        
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();
        int l = 0;
        int h = nums.size()-1;
      
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        int res = solve(nums,multipliers,l,h,0,dp);
        
        return res;
    }
};