class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = __builtin_popcount(nums[i]);
        }
        
        vector<int> v;
        
        for(auto x : mp){
            v.push_back(x.second);
        }
        
        sort(v.begin(),v.end());
        
        long long ans = 0;
        
        for(int i=0;i<v.size();i++){
            auto it = lower_bound(v.begin(),v.end(),k-v[i]);
            ans += (v.end()-it);
        }
        
        return ans;
        
    }
};