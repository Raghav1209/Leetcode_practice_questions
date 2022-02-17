class Solution {
public:
    
    void find(int pos,int target,vector<int> arr,vector<int> &comb,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        
        while(pos<arr.size() && arr[pos]<=target){
            comb.push_back(arr[pos]);
            find(pos,target-arr[pos],arr,comb,ans);
            
            pos++;
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> comb;
        find(0,target,arr,comb,ans);
        return ans;
    }
};