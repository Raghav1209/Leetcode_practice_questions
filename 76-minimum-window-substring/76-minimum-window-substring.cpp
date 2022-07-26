class Solution {
public:
    string minWindow(string s, string t) {
        string str;
        int lettercount = 0;
        
        if(s.empty() || t.empty()){
            return "";
        }
        
        
        
        unordered_map<int,int> map;
        unordered_map<int,int> window;
        int minLen = INT_MAX;
        int slow = 0;
        int fast;
        
        for(int i=0;i<t.size();i++){
            map[t[i]]++;
        }
        
        for(fast=0;fast<s.size();fast++){
            
            char c = s[fast];
            
            if(map.find(c)!=map.end()){
                
                window[c]++;
                
                if(window[c]<=map[c]){
                    lettercount++;
                }
                
            }
            
            if(lettercount>=t.size()){
                while(map.find(s[slow])==map.end() || window[s[slow]]>map[s[slow]]){
                    
                    window[s[slow]]--;
                    
                    slow++;
                    
                }
                
                if(fast-slow+1 < minLen){
                    minLen = fast-slow+1;
                    str = s.substr(slow,minLen);
                }
                
            }
            
            
            
        }
        
        return str;
        
    }
};