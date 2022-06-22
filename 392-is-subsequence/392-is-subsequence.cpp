class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0 && t.size()==0){
            return true;
        }
        int k = 0;
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[j]){
                k++;
                j++;
            }
            if(k==s.size()){
                return true;
            }
        }
        return false;
        
    }
};