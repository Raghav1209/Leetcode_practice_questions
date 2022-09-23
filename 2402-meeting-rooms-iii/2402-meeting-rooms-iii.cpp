class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        sort(meets.begin(),meets.end());
        vector<int> count(101,0);
        
        for(int i=0;i<n;i++){
            pq.push({meets[0][0],i});
        }
        
        for(int i=0;i<meets.size();i++){
            while(pq.top().first<meets[i][0]){
                pq.push({meets[i][0],pq.top().second});
                pq.pop();
            }
            
            pair<long long,int> curr = pq.top();
            pq.pop();
            long long time = curr.first;
            long long room = curr.second;
            
            pq.push({time+meets[i][1]-meets[i][0],room});
            count[room]++;
            
        }
        
        return max_element(count.begin(),count.end()) - count.begin() ;
        
    }
};