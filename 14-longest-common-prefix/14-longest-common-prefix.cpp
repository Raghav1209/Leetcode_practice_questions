class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        
        string str = strs[0];
        string res = "";
        for(int i=1;i<=str.size();i++){
            int flag =1;
            string ch = str.substr(0,i);
            int j=i;
            for(int i=1;i<strs.size();i++){
                if(ch!=strs[i].substr(0,j)){
                    flag=0;
                }
            }
            
            if(flag){
                res += str[i-1];
            }
            
            
        }
        
        return res;
        
    }
};