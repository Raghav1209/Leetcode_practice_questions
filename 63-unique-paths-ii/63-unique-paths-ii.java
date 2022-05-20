class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        int[][] path=new int[n][m];
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]==1){
                path[i][0]=0;
                break;
            }
            else{
                path[i][0]=1;
            }
        }
        for(int j=0;j<m;j++){
            if(obstacleGrid[0][j]==1){
                path[0][j]=0;
                break;
            }
            else{
                path[0][j]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    path[i][j]=0;
                    // break;
                }
                else{
                    path[i][j]=path[i-1][j]+path[i][j-1];
                }
            }
        }
        return path[n-1][m-1];
    }
}