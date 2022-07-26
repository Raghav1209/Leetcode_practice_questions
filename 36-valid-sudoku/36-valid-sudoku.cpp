class Solution {
public:
    
    bool isSafe(char num,vector<vector<char>> board,int row,int col){
        
        for(int i=0;i<9;i++){
            
            if(i==row){
                continue;
            }
            
            if(board[i][col]==num){
                return false;
            }
        }
        
        for(int i=0;i<9;i++){
            
            if(i==col){
                continue;
            }
            
            if(board[row][i]==num){
                return false;
            }
        }
        
        int s = sqrt(9);
        int rs = row-row%s;
        int cs = col-col%s;
            
        for(int i=rs;i<rs+s;i++){
            for(int j=cs;j<cs+s;j++){
                
                if(i==row && j==col){
                    continue;
                }
                
                if(board[i][j]==num){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    
                    if(isSafe(board[i][j],board,i,j)==false){
                        return false;
                    }
                    
                   
                }
                
            }
            
        }
        
        return true;
        
        
        
        
        
    }
};