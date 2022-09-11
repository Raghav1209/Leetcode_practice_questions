class Solution {
public:
    
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        
        if(a.first==b.first){
            return a.second>b.second;
        }
            
        return a.first<b.first;
        
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<p.size();i++){
            v.push_back({p[i][0],p[i][1]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
    
        int minn = INT_MIN;
        int count = 0;
        for(int i=p.size()-1;i>=0;i--){
            
            if(v[i].second<minn){
                count++;
            }
            
            minn = max(minn,v[i].second);
            
        }
        
        return count;
        
    }
};