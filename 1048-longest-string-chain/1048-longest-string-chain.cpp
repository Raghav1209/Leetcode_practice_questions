class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int res = 1;
        unordered_map<string,int> dp;
        sort(words.begin(), words.end(), [](const string &a, const string &b) 
                  {return a.length() < b.length(); });
        
        for(string word : words){
            dp[word] = 1;
            for(int i=0;i<word.size();i++){
                string prev = word.substr(0,i) + word.substr(i+1);
                if(dp.find(prev)!=dp.end()){
                    dp[word] = max(dp[word],dp[prev]+1);
                    res = max(res,dp[word]);
                }
            }
        }
        
//         for(auto x : dp){
//             cout<<x.first<<"->"<<x.second<<endl;
//         }
        
        return res;
        
    }
};