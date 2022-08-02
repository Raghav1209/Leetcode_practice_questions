class Solution {
public:
    
    bool find(vector<vector<char>> &board,string word,int index,int i,int j,vector<vector<bool>> &vis){
        
        if(index==word.size()){
            return true;
        }
        vis[i][j] = true;
        if(board[i][j]==word[index]){
            
            if(i+1<board.size() && !vis[i+1][j] && find(board,word,index+1,i+1,j,vis)){
                return true;
            }
            if(i-1>=0 && !vis[i-1][j] && find(board,word,index+1,i-1,j,vis)){
                return true;
            }
            if(j+1<board[0].size() && !vis[i][j+1] && find(board,word,index+1,i,j+1,vis)){
                return true;
            }
            if(j-1>=0 && !vis[i][j-1] && find(board,word,index+1,i,j-1,vis)){
                return true;
            }
            if(index+1==word.size()){
                return true;
            }
        }
        vis[i][j] = false;
        return false;
           
        
    }
    
    bool exist(vector<vector<char>>& board, string word){
       
        
        // string word;
       
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        // vector<string> ans;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(!vis[i][j] && find(board,word,0,i,j,vis)){
                        return true;
                    }
                }
               
            }

        
        return false;
        
    }
};