class Solution {
public:
    
    struct cmp{
        bool operator()(pair<int,string> &a,pair<int,string> &b){
            if(a.first<b.first){
                return true;
            }else if(a.first==b.first && a.second>b.second){
                return true;
            }else{
                return false;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        vector<string> ans;
        
        for(int i=words.size()-1;i>=0;i--){
            mp[words[i]]++;
        }
        
        // for(auto x : mp){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        
        for(auto x : mp){
            pq.push({x.second,x.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
        
    }
};