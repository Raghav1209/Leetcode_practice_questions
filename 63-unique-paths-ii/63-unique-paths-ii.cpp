class Solution {
public:
    
    int DFS(vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){
        
        
        if(n<0 || m<0 || n>grid.size() || m>grid[0].size()){
            return 0;
        }
        
        if(grid[n][m]==1){
            return 0;
        }
        
        if(n==0 && m==0){
            return 1;
        }
        
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        
        
        int count = 0;
        count += DFS(grid,n-1,m,dp) + DFS(grid,n,m-1,dp);
        
        return dp[n][m] = count;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return DFS(grid,n-1,m-1,dp);
        
    }
};