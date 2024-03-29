class Solution {
public:
    
    void solve(int prev,int k,int sum,int n,vector<vector<int>> &ans,vector<int> &temp){
        if(k==0){
            if(sum==n){
                ans.push_back(temp);
                return;
            }
        }
        
        for(int i=prev;i<=9;i++){
            temp.push_back(i);
            solve(i+1,k-1,sum+i,n,ans,temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(1,k,0,n,ans,temp);
        return ans;
    }
};