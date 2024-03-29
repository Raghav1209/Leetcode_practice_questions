class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
         int n = strs.size();
        
        if(n==1){
            return strs[0];
        }
        sort(strs.begin(),strs.end());
       
        string a = strs[0];
        string b = strs[n-1];
        string res = "";
        
        for(int i=0;i<b.size();i++){
            if(a[i]==b[i]){
                res+=a[i];
            }else 
                break;
        }
        
        return res;
        
    }
};