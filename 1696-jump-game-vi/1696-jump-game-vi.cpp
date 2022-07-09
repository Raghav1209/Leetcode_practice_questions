class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
       int dp[n];
        
        dp[n-1] = nums[n-1];
        priority_queue<pair<int,int>> maxh;
        maxh.push({dp[n-1],n-1});
        
        for(int i=nums.size()-2;i>=0;i--){
            
            while(!maxh.empty() && maxh.top().second>i+k){
                maxh.pop();
            }
            
            dp[i] = maxh.top().first + nums[i];
            
            maxh.push({dp[i],i});
            
        }
        return dp[0];
        
    }
};