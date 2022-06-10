class Solution {
public:
    
    void find(int index,int sum,vector<int> arr,vector<int> curr,set<vector<int>> &s){
        
        if(sum<0){
            return;
        }
        
        if(sum==0){
            s.insert(curr);
            return;
        }
        
        for(int i=index;i<arr.size();i++){
            curr.push_back(arr[i]);
            find(i,sum-arr[i],arr,curr,s);
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> curr;
        find(0,target,arr,curr,s);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};