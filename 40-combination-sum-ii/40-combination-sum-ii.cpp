class Solution {
public:
    
    void solve(vector<int> nums,int sum,set<vector<int>> &s,vector<int> v,int index){
        
        if(sum<0){
            return;
        }
        
        if(sum==0){
            // sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            
            // if(sum<nums[i]){
            //     break;
            // }
            
            v.push_back(nums[i]);
            solve(nums,sum-nums[i],s,v,i+1);
            v.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(nums,target,s,v,0);
        
        for(auto x : s){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};