class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size()<s1.size()){
            return false;
        }
        
        vector<int> freq(26,0);
        vector<int> v(26,0);
        int n = s1.size();
        
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
            v[s2[i]-'a']++;
        }
        
        if(v==freq){
            return true;
        }
        
        for(int i=0;i<s2.size()-n;i++){
            
            v[s2[i]-'a']--;
            v[s2[i+n]-'a']++;
            
            if(v==freq){
                return true;
            }
            
        }
        
        return false;
        
    }
};