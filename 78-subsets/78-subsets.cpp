class Solution {
public:
    
    void solve(vector<int> arr,int n,vector<int> v,vector<vector<int>> &ans){
        
        if(n==0){
            ans.push_back(v);
            return;
        }
        
        solve(arr,n-1,v,ans);
        v.push_back(arr[n-1]);
        solve(arr,n-1,v,ans);
        
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> v;
        solve(arr,n,v,ans);
        return ans;
        
    }
};