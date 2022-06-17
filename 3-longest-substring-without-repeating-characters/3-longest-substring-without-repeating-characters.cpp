class Solution {
public:
    
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    
    int lengthOfLongestSubstring(string s) {
        
        // unordered_map<int,int> mp;
        // int max_len = 0;
        // for(int st=0;st<s.size();st++){
        //     int i=st;
        //     while(i<s.size() && mp[s[i]]<1){
        //         mp[s[i]]++;
        //         i++;
        //     }
        //     max_len = max(max_len,mp.size());
        //     mp.clear();
        // }
        // return max_len;
        
        vector<int> dict(256,-1);
        int start = -1;
        int max_len = 0;
        
        for(int i=0;i<s.size();i++){
            if(dict[s[i]]>start){
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            max_len = max(max_len,i-start);
        }
        return max_len;
        
    }
};