class Solution {
public:
    
    bool dp[100001];
    
    
    bool winnerSquareGame(int n) {
        
        if(n==0){
            return false;
        }
        if(dp[n]!=NULL){
            return dp[n];
        }
        int winner = 0;
        for(int i=1;i*i<=n;i++){
            if(winnerSquareGame(n-(i*i))==false){
                winner = 1;
                break;
            }
        }
        
        dp[n]=winner;
        return dp[n];
    
        
    }
};