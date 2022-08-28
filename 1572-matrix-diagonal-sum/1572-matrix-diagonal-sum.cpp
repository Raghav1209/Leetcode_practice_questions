class Solution {
public:
    
    int solveright(int i,int j,vector<vector<int>> &mat){
        int di = i;
        int dj = j;
        int sum = 0;
        while(di<mat.size() && dj<mat[0].size()){
            sum += mat[di][dj];
            di++;
            dj++;
        }
        return sum;
    }
    
    int solveleft(int i,int j,vector<vector<int>> &mat){
        int di = i;
        int dj = j;
        int sum = 0;
        while(di<mat.size() && dj>=0){
            sum += mat[di][dj];
            di++;
            dj--;
        }
        return sum;
    }
    
    int diagonalSum(vector<vector<int>>& mat) {
        
        int x = solveright(0,0,mat);
        int y = solveleft(0,mat[0].size()-1,mat);
        
        if(mat.size()%2!=0){
            int mid = mat.size()/2;
            return x+y-mat[mid][mid];
        }else{
            return x+y;
        }
        
    }
};