class Solution {
public:
    
    void solve(vector<int> nums,int n,int index,vector<int> v,set<vector<int>> &s){
        
        if(index==n){
            sort(v.begin(),v.end());
            s.insert(v);
            return;
        }
        
        solve(nums,n,index+1,v,s);
        v.push_back(nums[index]);
        solve(nums,n,index+1,v,s);
        
    }
    
    vector<vector<int>> ans;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> v;
        int n = nums.size();
        set<vector<int>> s;
        solve(nums,n,0,v,s);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
        
    }
};