class Solution {
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        
        vector<pair<int,int>> v;
        vector<vector<int>> ans;
        
        for(int i=0;i<b.size();i++){
            vector<int> vc = b[i];
            v.push_back({vc[0],-1*vc[2]});
            v.push_back({vc[1],vc[2]});
        }
        
        
        
        multiset<int,greater<int>> pq;
        pq.insert(0);
        
        int curr_ht = 0;
        
        sort(v.begin(),v.end());
        
        // for(auto x : v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        for(auto x : v){
            
            int co = x.first;
            int ht = x.second;
            
            if(ht<0){
                pq.insert(-ht);
            }else{
               pq.erase(pq.find(ht));
            }
            
            if(curr_ht!=*pq.begin()){
                vector<int> a;
                a.push_back(co);
                a.push_back(*pq.begin());
                curr_ht = *pq.begin();
                ans.push_back(a);
            }
            
        }
        
        return ans;
        
    }
};