class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                int letters = i-mp[s[i]]-1;
                if(letters!=distance[s[i]-'a']){
                    return false;
                }
            }else{
                mp[s[i]] = i;
            }
        }
        return true;
    }
};