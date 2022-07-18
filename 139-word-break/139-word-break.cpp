class Solution {
public:
    
    bool solve(string s,vector<string> &wordDict,unordered_map<string,bool> &dp){
        
        if(s.size()==0){
            return 1;
        }
        
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        
        // int flag;
        for(int i=1;i<=s.size();i++){
            // flag=0;
            string ss = s.substr(0,i);
            // for(int j=0;j<wordDict.size();j++){
            //     if(ss.compare(wordDict[j])==0){
            //         flag = 1;
            //         break;
            //     }
            // }
            
            auto it = find(wordDict.begin(),wordDict.end(),ss) != wordDict.end();
            
            if(it && solve(s.substr(i),wordDict,dp)){
                return dp[s] = true;
                // return true;
            }
            
        }
        
        return dp[s] = false;
        // return false;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,bool> dp;
        return solve(s,wordDict,dp);
        
//         if(x==1){
//             return true;
//         }
        
//         if(x==-1){
//             return false;
//         }
        
//         return true;
        

    }
};