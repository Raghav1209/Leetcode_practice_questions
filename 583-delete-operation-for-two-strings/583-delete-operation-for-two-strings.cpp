class Solution {
public:
    
//     int solve(string word1,string word2,int m,int n){
//         if(m==0){
//             return n;
//         }
        
//         if(n==0){
//             return m;
//         }
        
//         if(word1[m-1]==word2[n-1]){
//             return solve(word1,word2,m-1,n-1);
//         }
        
//         return min(solve(word1,word2,m-1,n),solve(word1,word2,m,n-1)) + 1;
        
//     }
    
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        // return solve(word1,word2,m,n);
        
        int dp[m+1][n+1];
        
        for(int i=0;i<=n;i++){
            dp[0][i] = i;
        }
        
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        return dp[m][n];
        
    }
};