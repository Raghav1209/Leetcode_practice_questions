class Solution {
public:
    
    bool allWild(string &s){
        for(int i=0;i<s.size();i++){
            if(s[i]!='?'){
                return false;
            }
        }
        return true;
    }
    
    bool match(string &stamp,string &str){
        
        if(stamp.size()!=str.size()){
            return false;
        }
        
        for(int i=0;i<str.size();i++){
            if(stamp[i]!=str[i] && stamp[i]!='?' && str[i]!='?'){
                return false;
            }
        }
        
        return true;
        
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        bool foundMatch = true;
        string str;
        int n = target.size();
        int m = stamp.size();
        
        while(foundMatch){
            foundMatch = false;
            for(int i=0;i<n-m+1;i++){
                str = target.substr(i,m);
                
                if(allWild(str)){
                    continue;
                }
                
                if(match(stamp,str)){
                    foundMatch = true;
                    ans.push_back(i);
                    
                    for(int j=0;j<m;j++){
                        target[i+j] = '?';
                    }
                    
                }
                
            }
        }
        
        if(allWild(target)==false){
            ans.clear();
        }
        
        if(ans.size()>10*n){
            ans.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};