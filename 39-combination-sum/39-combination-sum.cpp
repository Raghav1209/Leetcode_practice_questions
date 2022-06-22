class Solution {
public:
    void solve(vector<int> nums,int n,vector<int> v,set<vector<int>> &s,int index,int sum){
        
        if(sum<0){
            return;
        }
        
        if(sum==0){
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        
        for(int i=index;i<n;i++){
            v.push_back(nums[i]);
            solve(nums,n,v,s,i,sum-nums[i]);
            v.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        vector<int> v;
        set<vector<int>> s;
        vector<vector<int>> ans;
        int n = candidates.size();
        solve(candidates,n,v,s,0,target);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
        
    }
};