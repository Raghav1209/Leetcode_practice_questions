class Solution {
public:
    
    bool isSafe(vector<vector<char>> &board,char n,int i,int j){
        // char num = n + '0';
        for(int k=0;k<9;k++){
            if(board[i][k]==n || board[k][j]==n){
                return false;
            }
        }
        
        int s = sqrt(9);
        int rs = i-(i%s);
        int cs = j-(j%s);
        
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(board[i+rs][j+cs]==n){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool solve(vector<vector<char>> &board,int n){
        int i,j;
        int flag=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='.'){
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        if(i==9 && j==9){
            return true;
        }
        
        for(char k='1';k<='9';k++){
            if(isSafe(board,k,i,j)){
                board[i][j] = k;
                if(solve(board,n)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board,9);
        
    }
};