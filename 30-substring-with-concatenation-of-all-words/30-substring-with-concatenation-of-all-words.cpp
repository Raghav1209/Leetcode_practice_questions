class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       
       int n = words.size();
       int x = words[0].length();
        
       int window = n*x;
        int s_len = s.length();
        vector<int> ans;
        
        unordered_map<string,int> f;
        
       for(auto x : words){
           f[x]++;
       } 
        
        int limit = s_len-window;
        
        for(int i=0;i<=limit;i++){
            unordered_map<string,int> m;
            int flag = 0;
            for(int j=i;j<s_len;j=j+x){
                string str = s.substr(j,x);
                if(f[str]>m[str]){
                    m[str]++;
                    flag++;
                }else{
                    break;
                }
            }
            if(flag==n){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};