class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        int n = strs.size();
        string str = "";
        unordered_map<string,vector<string>> mp;
        
       vector<string> v1;
        
        for(int i=0;i<n;i++){
            str = strs[i];
            sort(str.begin(),str.end());
            v1.push_back(str);
            str = "";
        }
        
        
        
        for(int i=0;i<v1.size();i++){
            mp[v1[i]].push_back(strs[i]);
        }
        
        for(auto x : mp){
           vector<string> v2 = x.second;
            v.push_back(v2);
        }
        
        
        return v;
    }
};