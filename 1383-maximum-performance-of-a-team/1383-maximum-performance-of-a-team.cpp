class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        long res = 0;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        long sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(rbegin(v),rend(v));
        
        for(pair<int,int> x : v){
            
            int e = x.first;
            int s = x.second;
            
            sum += s;
            pq.push(s);
            while(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            
            
            res = max(res,sum*e);
            
        }
        
        return res%(int)1000000007;
        
    }
};