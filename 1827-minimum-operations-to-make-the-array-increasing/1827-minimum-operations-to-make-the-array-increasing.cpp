class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int x = abs(nums[i]-nums[i-1])+1;
                ans += x;
                nums[i] = nums[i-1]+1;
            }
        }
        
        return ans;
        
    }
};