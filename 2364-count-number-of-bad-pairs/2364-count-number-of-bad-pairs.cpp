class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long res;
        long long total = (((long long)nums.size())*((long long)nums.size()-1))/2;
        long long good = 0;
        
        unordered_map<long long,long long> mp;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-i)!=mp.end()){
                good += mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        
        res = total-good;
        
        return res;
        
    }
};