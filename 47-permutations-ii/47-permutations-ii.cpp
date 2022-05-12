class Solution {
public:
    
    void permute(vector<int> nums,int i,set<vector<int>> &s){
        if(i==nums.size()-1){
            s.insert(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permute(nums,i+1,s);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;
        
        permute(nums,0,s);
        
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
        
    }
};