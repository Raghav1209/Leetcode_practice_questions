class Solution {
public:
    int firstUniqChar(string s) {
        int n = 256;
        vector<int> count(n,0);
        
        for(int i=0;i<s.size();i++){
            count[s[i]-'0']++;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(count[s[i]-'0']==1){
                return i;
            }
        }
        
        return -1;
    }
};