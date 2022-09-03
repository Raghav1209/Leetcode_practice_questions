class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        unordered_map<int,pair<int,int>> s;
        
        for(int i=0;i<nums.size()-1;i++){
            s[nums[i]+nums[i+1]] = {i,i+1};
        }
        
        for(int i=nums.size()-1;i>=1;i--){
            if(s.find(nums[i]+nums[i-1])!=s.end()){
                pair<int,int> curr = {i-1,i};
                if(curr!=s[nums[i]+nums[i-1]]){
                    return true;
                }
            }
        }
        
        return false;
        
    }
};