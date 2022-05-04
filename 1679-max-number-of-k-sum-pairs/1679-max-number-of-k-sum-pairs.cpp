class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(k-nums[i])!=mp.end()){
                if(nums[i]==k-nums[i]){
                     if(mp[nums[i]]>=2){
                    count++;
                    mp[nums[i]]=mp[nums[i]]-2;
                    }
                }else{
                    if(mp[nums[i]]>0 && mp[k-nums[i]]>0){
                        count++;
                        mp[k-nums[i]]--;
                        mp[nums[i]]--;
                    }
                    
                }
               
            }
        }
        
        return count;
        
    }
};