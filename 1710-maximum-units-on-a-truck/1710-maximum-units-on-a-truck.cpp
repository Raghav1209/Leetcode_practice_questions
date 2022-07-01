class Solution {
public:
    

      static bool mycmp(pair<int,int> &a,pair<int,int> &b){
          return a.second>b.second;
      }  
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int w) {
        
        vector<pair<int,int>> v;
        
        for(auto x : boxTypes){
            v.push_back({x[0],x[1]});
        }
        
        sort(v.begin(),v.end(),mycmp);
        int ans = 0;
        
       for(int i=0;i<v.size();i++){
           if(v[i].first<=w){
               ans += v[i].first*v[i].second;
               w -= v[i].first;
           }else{
               ans += w*v[i].second;
               break;
           }
       }
        
        return ans;
        
    }
};