class Solution {
public:
    
    bool isStretchy(string s,string t){
        int n = s.size();
        int m = t.size();
        
        int i=0;
        int j=0;
        
        while(i<n && j<m){
            if(s[i]!=t[j]){
                return false;
            }
            char c = s[i];
            int c1 = 0;
            int c2 = 0;
            while(i<n && s[i]==c){
                i++;
                c1++;
            }
            
            while(j<m && t[j]==c){
                j++;
                c2++;
            }
            
            if(c1==c2){
                continue;
            }
            if(c1>c2){
                return false;
            }
            else if(c2>=3){
                continue;
            }
            
            return false;
            
        }
        
        if(i!=n || j!=m){
            return false;
        }
        return true;
        
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        
        for(int i=0;i<words.size();i++){
            if(isStretchy(words[i],s)){
                ans++;
            }
        }
        
        return ans;
        
    }
};