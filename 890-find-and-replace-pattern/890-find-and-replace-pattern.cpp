class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        
    
        int flag;
        for(string w : words){
            unordered_map<char,char> word;
            unordered_map<char,char> pat;
            flag=0;
            if(w.size()==pattern.size()){
                for(int i=0;i<pattern.size();i++){
                    if(pat.find(pattern[i])==pat.end() && word.find(w[i])==word.end()){
                        pat[pattern[i]] = w[i];
                        word[w[i]] = pattern[i];
                    }else{
                        
                        if(pat.find(pattern[i])!=pat.end() && word.find(w[i])!=word.end()){
                            
                            if(pat[pattern[i]]!=w[i]){
                                flag=1;
                                break;
                            }
                            
                        }else{
                            flag=1;
                            break;
                        }
                        
                    }
                }
                
                if(flag==0){
                    ans.push_back(w);
                }
                
            }else{
                continue;
            }
            
            
            
        }
        
        return ans;
        
        
    }
};