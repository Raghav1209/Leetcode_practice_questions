class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int count = 0;
        unordered_set<int> s;
        
        if(k==0){
            unordered_map<int,int> mp;
            for(int i=0;i<nums.size();i++){
                mp[nums[i]]++;
            }
            
            for(auto x : mp){
                if(x.second>1){
                    count++;
                }
            }
            
            return count;
            
        }
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        nums.erase(nums.begin(),nums.end());
        
        for(auto x : s){
            nums.push_back(x);
        }
        
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]+k)!=s.end()){
                count++;
            }
        }
        
        return count;
        
    }
};