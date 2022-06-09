class Solution {
public:
    
    bool isSafe(vector<string> &board,int row,int col,int n){
        int i,j;
        for(int i=col;i>=0;i--){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        
        i=row;
        j=col;
        
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        
        i = row;
        j = col;
        
        while(i<n && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }
    
    void solve(vector<string>& board,int col,int n){
        
        if(col==n){
            sols.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(board,i,col,n)){
                board[i][col] = 'Q';
                
                solve(board,col+1,n);
                
                board[i][col] = '.';
                
            }
        }
        
        
        
    }
    
    vector<vector<string>> sols;
    vector<vector<string>> solveNQueens(int n) {
        
        
        
        vector<string> board(n, string(n, '.'));
        
            solve(board,0,n);
            // sols.push_back(board);
            return sols;
        }
        
    
};