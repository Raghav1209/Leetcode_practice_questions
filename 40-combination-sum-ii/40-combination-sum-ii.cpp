class Solution {
public:
    
    void solve(vector<int> &nums,int idx,vector<int> &v,vector<vector<int>> &ans,int target){
        
        
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        if(target<0){
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            
            v.push_back(nums[i]);
            solve(nums,i+1,v,ans,target-nums[i]);
            v.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums,0,v,ans,target);
        return ans;
        
    }
};