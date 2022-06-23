// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m,vector<vector<bool>> &vis,int x,int y,int n){
       
       if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && vis[x][y]==false){
           return true;
       }else{
           return false;
       }
        
    }
    
    void solve(vector<vector<int>> &m,vector<string> &ans,string &str,
    vector<vector<bool>> &vis,int x,int y,int n){
        
        if(x==n-1 && y==n-1){
            ans.push_back(str);
            return;
        }
        
        vis[x][y] = true;
        
        if(isSafe(m,vis,x+1,y,n)){
            str += 'D';
            solve(m,ans,str,vis,x+1,y,n);
            str.pop_back();
        }
        
        if(isSafe(m,vis,x,y+1,n)){
            str += 'R';
            solve(m,ans,str,vis,x,y+1,n);
            str.pop_back();
        }
        
        if(isSafe(m,vis,x-1,y,n)){
            str += 'U';
            solve(m,ans,str,vis,x-1,y,n);
            str.pop_back();
        }
        
        if(isSafe(m,vis,x,y-1,n)){
            str += 'L';
            solve(m,ans,str,vis,x,y-1,n);
            str.pop_back();
        }
        
        vis[x][y] = false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        
        
        string str = "";
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(m,ans,str,vis,0,0,n);
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends