class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i = 0;
        int j = matrix[0].size()-1;
        int r = matrix.size();
        int c = matrix[0].size();
        
        while(i<r && j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                
                i++;
                
            }else{
                j--;
            }
        }
        return false;
        
        
    }
};