class Solution {
public:
    int titleToNumber(string s) {
        
        if(s.length()==1){
            return s[0]-'@';
        }
       int ans = 0;
        int power = 0;
        // int val;
        for(int i = s.length()-1;i>=0;i--){
            ans = ans + ((s[i]-'@') * pow(26,power));
            power = power+1;
        }
        
        return ans;
    }
};