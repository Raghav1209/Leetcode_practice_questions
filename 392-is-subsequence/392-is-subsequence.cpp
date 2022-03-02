class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.length()-1;
        int j = t.length()-1;
        
        while(i>=0 && j>=0){
            if(t[j]!=s[i]){
                j--;
            }else{
                i--;
                j--;
            }
        }
        
        if(i<0 && j<0){
            return true;
        }
        
        if(j>=0 && i<0){
            return true;
        }else{
            return false;
        }
    }
};