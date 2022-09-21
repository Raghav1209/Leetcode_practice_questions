class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                sum += nums[i];
        }
        
        for(int i=0;i<queries.size();i++){
            int idx = queries[i][1];
            int val = queries[i][0];
            
            int oldVal = nums[idx];
            nums[idx] += val;
            
            bool wasEven = (oldVal%2)==0;
            bool nowEven = (nums[idx]%2)==0;
            
            if(wasEven && nowEven){
                ans[i] = sum + val;
                sum += val;
            }else if(wasEven && !nowEven){
                ans[i] = sum-oldVal;
                sum -= oldVal;
            }else if(!wasEven && nowEven){
                 ans[i] = sum+nums[idx];
                sum += nums[idx];
               
            }else{
                ans[i] = sum;
            }
            
        }
        
        return ans;
        
    }
};