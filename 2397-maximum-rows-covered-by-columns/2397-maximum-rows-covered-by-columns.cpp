class Solution {
public:
    int ans = 0;
    int covered(vector<vector<int>> &mat){
        
        // int flag;
        int count = 0;
        for(int i=0;i<mat.size();i++){
            int flag = 1;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    flag = 0;
                }
            }
            if(flag){
                count++;
            }
        }
        
        return count;
        
    }
    
    int solve(vector<vector<int>> &mat,int col,int i){
        
        if(col==0 || i==mat[0].size()){
            int c = covered(mat);
            ans = max(ans,c);
            return c;
        }
        
        int x = solve(mat,col,i+1);
        
        vector<vector<int>> cmat = mat;
        
        for(int j=0;j<mat.size();j++){
            cmat[j][i] = 0; 
        }
        
        int y = solve(cmat,col-1,i+1);
        
        return max(x,y);
        
    }
    
    int maximumRows(vector<vector<int>>& mat, int col) {
        
        solve(mat,col,0);
        return ans;
    }
};