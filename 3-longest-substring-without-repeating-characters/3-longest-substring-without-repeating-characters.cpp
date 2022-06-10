class Solution {
public:
    
    int max_ele(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    
    int lengthOfLongestSubstring(string s) {
        
        if(s.size()==0){
            return 0;
        }
        
        unordered_map<int,int> mp;
        
        int st;
        int maxx = INT_MIN;;
        for(st=0;st<s.size();st++){
            
            int i=st;
            while(i<s.size() && mp[s[i]]<1){
                mp[s[i]]++;
                i++;
            }
            
            maxx = max_ele(maxx,mp.size());
            mp.clear();
        }
        
        return maxx;
        
    }
};