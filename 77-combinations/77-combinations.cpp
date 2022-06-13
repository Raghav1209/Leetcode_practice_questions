class Solution {
public:
    
    void solve(int n,int k,vector<int> curr,int index,set<vector<int>> &s){
        
        if(curr.size()==k){
            sort(curr.begin(),curr.end());
            // for(int i=0;i<curr.size();i++){
            //     cout<<curr[i]<<" ";
            // }
            // cout<<endl;
            s.insert(curr);
            return;
        }
        
        for(int i=index;i<=n;i++){
            curr.push_back(i);
            solve(n,k,curr,i+1,s);
            curr.pop_back();
        }
        
    }
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> s;
        vector<int> curr;
        solve(n,k,curr,1,s);
        
        for(auto x : s){
            ans.push_back(x);
        }
        
        return ans;
    }
};