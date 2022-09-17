class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0;i<operations.size();i++){
            
            int x = operations[i][0];
            int y = operations[i][1];
            
            if(mp.find(x)!=mp.end()){
    
                nums[mp[x]] = y;
                mp[y] = mp[x];
                mp.erase(x);
            }
            
        }
        
        return nums;
        
    }
};