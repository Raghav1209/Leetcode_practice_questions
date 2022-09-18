class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int maxx = 0;
        int count = 1;
        for(int i=1;i<s.size();i++){
            if((s[i]-'a')==(s[i-1]-'a')+1){
                count++;
            }else{
                maxx = max(maxx,count);
                count = 1;
            }
        }
        
        maxx = max(count,maxx);
        return maxx;
        
    }
};