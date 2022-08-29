class Solution {
public:
    
    bool isPalindrome(string s){
        int l = 0;
        int h = s.size()-1;
        
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
        
    }
    
    bool validPalindrome(string s) {
        
        int l = 0;
        int h = s.size()-1;
        int count = 0;
        while(l<h){
            if(s[l]==s[h]){
                l++;
                h--;
            }else if(s[l]==s[h-1] && isPalindrome(s.substr(l,h-l))){
                return true;
            }else if(s[h]==s[l+1] && isPalindrome(s.substr(l+1,h-l))){
               return true;
            }else{
                return false;
            }
        }
        return true;
        
    }
};