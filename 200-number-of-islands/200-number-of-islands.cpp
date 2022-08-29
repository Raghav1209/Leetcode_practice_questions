class Solution {
public:
    
    void DFS(vector<vector<char>> &grid,vector<vector<bool>> &vis,int i,int j){
        
        vis[i][j] = true;
        
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]=='1'){
            DFS(grid,vis,i-1,j);
        }
        
        if(i+1<grid.size() && !vis[i+1][j] && grid[i+1][j]=='1'){
            DFS(grid,vis,i+1,j);
        }
        
        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]=='1'){
            DFS(grid,vis,i,j-1);
        }
        
        if(j+1<grid[0].size() && !vis[i][j+1] && grid[i][j+1]=='1'){
            DFS(grid,vis,i,j+1);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    DFS(grid,vis,i,j);
                    count++;
                }
            }
        }
        
        return count;
        
    }
};