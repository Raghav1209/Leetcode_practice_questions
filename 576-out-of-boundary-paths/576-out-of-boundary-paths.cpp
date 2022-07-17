class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int solve(int m,int n,int maxMove,int sr,int sc,vector<vector<vector<int>>> &dp){
        
    
        
        if(sr<0 || sc<0 || sr>=m || sc>=n){
            return 1;
        }
        
        if(maxMove==0){
            return 0;
        }
        
        if(dp[sr][sc][maxMove]!=-1){
            return dp[sr][sc][maxMove];
        }
        
            
        int x = solve(m,n,maxMove-1,sr-1,sc,dp);
        int y = solve(m,n,maxMove-1,sr+1,sc,dp);
        int z = solve(m,n,maxMove-1,sr,sc-1,dp);
        int r = solve(m,n,maxMove-1,sr,sc+1,dp);
        count = ((x + y)%mod + (z + r)%mod)%mod;  
        dp[sr][sc][maxMove] = count;
        return dp[sr][sc][maxMove];
    }
    
    int count = 0;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
            vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
            return solve(m,n,maxMove,startRow,startColumn,dp)%mod;
            
            // return count;
        
    }
};