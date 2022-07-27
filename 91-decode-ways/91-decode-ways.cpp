class Solution {
public:
    
    int solve(string s,int idx,vector<int> &dp){
        
        
        
        if(idx==s.size()){
            return 1;
        }
        
        
        
         if(dp[idx]!=-1){
            return dp[idx];
        }
        
        if(s[idx]=='0'){
            return 0;
        }
        
        if(idx==s.size()-1){
            return 1;
        }
        
        string temp = s.substr(idx,2);
        
        int op1 = solve(s,idx+1,dp);
        int op2=0;
        if(stoi(temp)>0 && stoi(temp)<=26){
             op2 = solve(s,idx+2,dp);
        }
        
        return dp[idx] = op1+op2;
        
    }
    
    int numDecodings(string s) {
        
        vector<int> dp(s.size()+1,-1);
        return solve(s,0,dp);
        
    }
};