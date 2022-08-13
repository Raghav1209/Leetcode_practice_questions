class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long count = 0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==0){
                count++;
            }
            
            if(nums[i]==0 && mp.find(nums[i])!=mp.end()){
            
                count += mp[nums[i]];
                
            }else{
                mp.clear();
            }
            
            mp[nums[i]]++;
            
        }
        
        return count;
        
    }
};