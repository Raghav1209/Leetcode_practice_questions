class Solution {
public:
    
    bool isSafe(vector<vector<string>> &ans,vector<string> &v,int row,int col,int n){
        int i,j;
        for(int k=col;k>=0;k--){
            if(v[row][k]=='Q'){
                return false;
            }
        }
        
        i=row;
        j=col;
        
        while(i>=0 && j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i=row;
        j=col;
        
        while(i<n && j>=0){
            if(v[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void solve(vector<vector<string>> &ans,vector<string> &v,int col,int n){
        
        if(col==n){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<n;i++){
            
            if(isSafe(ans,v,i,col,n)){
                v[i][col] = 'Q';
                solve(ans,v,col+1,n);
                v[i][col] = '.';
            }
            
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        
        
        string str(n,'.');
        
        vector<vector<string>> ans;
        
        vector<string> v(n,str);
        
       solve(ans,v,0,n);
        
        return ans;
        
       
        
        
    }
};