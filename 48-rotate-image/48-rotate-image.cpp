class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size()-1;
        
        int i=0;
        int j = n;
        
        while(i<j){
            for(int k=0;k<=n;k++){
                swap(matrix[i][k],matrix[j][k]);
            }
            i++;
            j--;
        }
        int grid[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                grid[j][i] = matrix[i][j];
            }
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                matrix[i][j] = grid[i][j];
            }
        }
        
    }
};