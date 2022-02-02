class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        
        int flag=1;
        vector<int> v;

        if(s_len<p_len){
            return v;
        }
        
        vector<int> f_p(26,0);
        vector<int> f_s(26,0);
        
        for(int i=0;i<p_len;i++){
            f_p[p[i]-'a']++;
            f_s[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(f_s[i]!=f_p[i]){
                flag = 0;
                break;
            }
        }
        
        if(flag){
            v.push_back(0);
        }
        
        for(int i=p_len;i<s_len;i++){
            f_s[s[i-p_len]-'a']--;
            f_s[s[i]-'a']++;
            
            if(f_s==f_p){
                v.push_back(i-p_len+1);
            }
            
        }
        
        return v;
    }
};