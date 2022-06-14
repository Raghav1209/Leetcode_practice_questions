class Solution {
public:
    
    
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        int table[n][n];
        memset(table,0,sizeof(table));
        int maxlength = 0;
        string str = "";
        int start;
        
        for(int i=0;i<n;i++){
            table[i][i] = 1;
            maxlength = 1;
            start = i;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                // str = "";
                table[i][i+1] = 1;
                start = i;
                maxlength = 2;
    
                
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;
                
                if(table[i+1][j-1] == 1 && s[i]==s[j]){
                    // str = "";
                    table[i][j] = 1;
                    
                    if(k>maxlength){
                        start = i;
                        maxlength = k;
                    }
                
                }
                
            }
        }
        
        // cout<<maxlength<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<table[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for(int i=start;i<=start+maxlength-1;i++){
            str += s[i];
        }
        
        return str;
        
    }
};