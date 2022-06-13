class Solution {
public:
    
    void solve(vector<int> nums,int l,int r){
        
        if(l==r){
            ans.push_back(nums);
            return;
        }
        
        for(int i=l;i<=r;i++){
            swap(nums[i],nums[l]);
            solve(nums,l+1,r);
            swap(nums[i],nums[l]);
        }
        
    }
        
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        solve(nums,0,n-1);
        return ans;
    }
};