class Solution {
public:
    
    string convert(int n,int i){
        string str = "";
        
        while(n){
            str += to_string(n%i);
            n = n/i;
        }
        return str;
    }
    
    bool isPalindrome(string s){
        int l=0;
        int h=s.size()-1;
        
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n-2;i++){
            string s = convert(n,i);
            if(!isPalindrome(s)){
                return false;
            }
        }
        
        return true;
        
        
    }
};