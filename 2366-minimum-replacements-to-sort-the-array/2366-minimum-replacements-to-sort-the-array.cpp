class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int nxt = 1e9;
        long long ans = 0;
        for(int j=nums.size()-1;j>=0;j--){
            
            if(nums[j]<=nxt){
                nxt = nums[j];
                    continue;
            }
            
            long long parts = ceil(nums[j]/(double)nxt);
            
            ans += (parts-1);
            
            nxt = nums[j]/parts;
            
        }
        
        return ans;
        
        
    }
};