class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string str1 = "";
        string str2 = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(str1.size()==0){
                    continue;
                }
                str1.pop_back();
            }else{
                str1 += s[i];
            }
        }
        
        
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                 if(str2.size()==0){
                    continue;
                }
                str2.pop_back();
            }else{
                str2 += t[i];
            }
        }
        
        return (str1==str2);
        
        
    }
};