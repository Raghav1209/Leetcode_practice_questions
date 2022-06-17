class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        
         sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int res = 1;
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            // mp[nums[i]] = 1;
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = 1;
            }
            if(mp.find(nums[i]-1)!=mp.end()){
                mp[nums[i]] = max(mp[nums[i]-1],mp[nums[i]])+1;
                res = max(res,mp[nums[i]]);
            }
            
        }
        return res;
        
    }
};