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
//         for(int i=1;i<=str.size();i++){
//             int flag =1;
//             string ch = str.substr(0,i);
//             int j=i;
//             for(int i=1;i<strs.size();i++){
//                 if(ch!=strs[i].substr(0,j)){
//                     flag=0;
//                 }
//             }
            
//             if(flag){
//                 res += str[i-1];
//             }
            
            
//         }
        
        for(int i=0;i<b.size();i++){
            if(a[i]==b[i]){
                res+=a[i];
            }else break;
        }
        
        return res;
        
    }
};