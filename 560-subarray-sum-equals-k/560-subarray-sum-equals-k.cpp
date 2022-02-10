class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        unordered_map<int,vector<int>> mp;
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<nums.size();i++){
            
            sum += nums[i];
            if(sum == k){
                count++;
            }
            
            if(mp.find(sum-k)!=mp.end()){
                vector<int> vc = mp[sum-k];
                for(int i=0;i<vc.size();i++){
                    count++;
                }
            }
            
            mp[sum].push_back(i);
            
        }
        
        return count;
        
    }
};