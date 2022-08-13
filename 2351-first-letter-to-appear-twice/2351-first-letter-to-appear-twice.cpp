class Solution {
public:
    char repeatedCharacter(string s) {
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.size();i++){
            
            if(mp.find(s[i])!=mp.end()){
                return s[i];
            }else{
                mp[s[i]] = i;
            }
            
        }
        
        return '#';
        
    }
};