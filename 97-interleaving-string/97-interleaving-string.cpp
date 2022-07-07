// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
        
//         int m = s1.size();
//         int n = s2.size();
//         int k = s3.size();
        
//         if(m+n !=k){
//             return false;
//         }
        
//         while(m>0 && n>0 && s1[m-1]==s2[n-1] && s1[m-1]==s3[k-1]){
//             m--;
//             n--;
//             k--;
//         }
        
//         if(m==0 && n==0){
//             return true;
//         }
        
//         if(m==0){
//             return s2.substr(0,n)==s3.substr(0,n);
//         }
        
//         if(n==0){
//             return s1.substr(0,m) == s3.substr(0,m);
//         }
        
//         if(s1[m-1]==s3[k-1]){
//             return isInterleave(s1.substr(0,m-1),s2,s3.substr(0,k-1));
//         }
        
//         if(s2[n-1]==s3[k-1]){
//             return isInterleave(s1,s2.substr(0,n-1),s3.substr(0,k-1));
//         }
        
//         return false;
        
//     }
// };

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                else dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};