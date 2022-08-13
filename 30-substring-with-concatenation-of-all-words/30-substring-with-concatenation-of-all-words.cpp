class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int x = words[0].size();
        int n = words.size();
        unordered_map<string,int> mp1;
        
        for(string str : words){
            mp1[str]++;
        }
        
        int sz = n*x; 
        int lim = s.size()-sz;
        
        for(int i=0;i<=lim;i++){
            unordered_map<string,int> mp2;
            int flag = 0;
            for(int j=i;j<s.size();j=j+x){
                string check = s.substr(j,x);
                
                if(mp1[check]>mp2[check]){
                    // cout<<check<<" ";
                    mp2[check]++;
                    flag++;
                    
                }else{
                    break;
                }
            }
            
            
            if(flag==n){
                ans.push_back(i);
                // i = i+sz;
            }
            
        }
        
        return ans;
        

        
    }
};