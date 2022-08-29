class Solution {
public:
    
    void DFS(vector<vector<int>> &grid,int i,int j){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1){
            return;
        }
        
        grid[i][j] = 1;
        
        DFS(grid,i+1,j);
        DFS(grid,i-1,j);
        DFS(grid,i,j-1);
        DFS(grid,i,j+1);
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
                DFS(grid,i,0);
            
            if(grid[i][m-1]==0){
                DFS(grid,i,m-1);
            }

        }
        
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)
                DFS(grid,0,i);
            
            if(grid[n-1][i]==0){
                DFS(grid,n-1,i);
            }

        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    DFS(grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }
};