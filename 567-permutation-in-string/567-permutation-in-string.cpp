class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(int i=0;i<n;i++){
            v1[s1[i]-'a']++;
        }
        
        string str = s2.substr(0,n);
        
         for(int i=0;i<str.length();i++){
            v2[str[i]-'a']++;
        }
        
        if(v2==v1){
            return true;
        }
        
        for(int i=n;i<m;i++){
            v2[s2[i-n]-'a']--;
            v2[s2[i]-'a']++;
            
            if(v1==v2){
                return true;
            }
            
        }
        return false;
        
    }
};