class Solution {
public:
    
    
    int countSubstrings(string s) {
        int count=0;
        int n = s.length();
        bool dp[n][n];
        
        if(n==0){
            return 0;
        }
        
        // if(n==1){
        //     return 1;
        // }
        
        memset(dp,false,sizeof(dp));
        
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            count++;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                count++;
            }
        }
        
        int i,j;
        for(int length=3;length<=n;length++){
            for(i=0;i<n-length+1;i++){
                 j = i+length-1; 
                
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j] = true;
                count++;
            }
            }
            
        }
        
        return count;
        
    }
};