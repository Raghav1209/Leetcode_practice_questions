class Solution {
public:
    char findTheDifference(string s, string t) {
      
//         unordered_set<char> ss;
        
//         for(int i=0;i<s.length();i++){
//             ss.insert(s[i]);
//         }
        
//         for(int i=0;i<t.length();i++){
//             if(ss.find(t[i])==ss.end()){
//                 return t[i];
//             }
//         }
        
//         return '$';
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        
        if(flag==0){
            return t[t.length()-1];
        }
        
        return '$';
        
    }
};