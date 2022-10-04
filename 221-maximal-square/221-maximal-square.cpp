class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
            }else{
                dp[i][0] = 0;
            }
        }
        
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
            }else{
                dp[0][i] = 0;
            }
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                
                if(matrix[i][j]=='1'){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;

                }else{
                    dp[i][j] = 0;
                }                
            }
        }
        int maxx = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(dp[i][j]>maxx){
                    maxx = dp[i][j];
                }
            }
        }
        return maxx*maxx;
    }
};