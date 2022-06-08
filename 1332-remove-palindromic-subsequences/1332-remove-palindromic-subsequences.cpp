class Solution {
public:
    
    bool isPalindrome(string str){
        int i=0;
        int j = str.size()-1;
        
        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        int counta = 0;
        int countb = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                counta++;
            }else{
                countb++;
            }
        }
        
        if(counta==0 || countb==0){
            return 1;
        }else if(counta==countb){
            if(isPalindrome(s)){
                return 1;
            }else{
                return 2;
            }
        }else{
            if(isPalindrome(s)){
                return 1;
            }else{
                return 2;
            }
        }
        
        // return 0;
        
    }
};