class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        
        vector<int> ans;
        
        if(c.size()%2==1){
            return ans;
        }
        
        map<int,int> mp;
        
        for(int i=0;i<c.size();i++){
            mp[c[i]]++;
        }
        
        sort(c.begin(),c.end());
        
        for(int i=0;i<c.size();i++){
            
            if(mp[c[i]]==0){
                continue;
            }
            
            if(mp[c[i]*2]==0){
                return {};
            }
            
    
            ans.push_back(c[i]);
            mp[c[i]]--;
            mp[2*c[i]]--;
            
        }
        
        return ans;
        
    }
};