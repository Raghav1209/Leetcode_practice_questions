class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        int flag;
        string str = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(str);
                str = "";
            }else{
                str += s[i];
            }
        }
            v.push_back(str);
            str = "";
        
        if(pattern.length()!=v.size()){
            return false;
        }
        
        vector<string> check(256,"$");
        unordered_set<char> s1;
        unordered_set<string> s2;
        for(int i=0;i<pattern.length();i++){
            s1.insert(pattern[i]);
        }
        for(int i=0;i<pattern.length();i++){
            s2.insert(v[i]);
        }
        
        
        if(s1.size()==s2.size()){
             for(int i=0;i<pattern.length();i++){
            if(check[pattern[i]]=="$"){
                check[pattern[i]]=v[i];
            }else{
                if(check[pattern[i]]!=v[i]){
                    return false;
                }
            }
        }
            return true;
        }else{
            return false;
        }
       
    
        
        
      
    }
};