class Solution {
public:
   
    int solve(int i,int n,string vowels,vector<vector<int>> &dp){
        
        if(n==0){
            return 1;
        }
        
        if(i>=5){
            return 0;
        }
        int pick,notPick;
        if(dp[i][n]!=-1){
            return dp[i][n];
        }else{
            
            pick = solve(i,n-1,vowels,dp);
            notPick = solve(i+1,n,vowels,dp);
        }
        
        dp[i][n] = pick+notPick;
        return dp[i][n];
    }
    
    int countVowelStrings(int n) {
        
        string vowels = "aeiou";
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        
        return solve(0,n,vowels,dp);
        
    }
};