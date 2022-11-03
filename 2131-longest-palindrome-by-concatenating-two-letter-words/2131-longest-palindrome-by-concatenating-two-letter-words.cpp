class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        
        unordered_map<string,int> mp;
        int count = 0;
        for(string word : words){
            string rev = word;
            reverse(rev.begin(),rev.end());
            
            if(mp[rev]>0){
                count += 4;
                mp[rev]--;
            }else{
                mp[word]++;
            }
            
        }
        
        for(string x : words){
            
            if(x[0]==x[1] && mp[x]>0){
                count += 2;
                break;
            }
        }
        return count;
    }
};