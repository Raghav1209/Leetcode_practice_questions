class Solution {
public:
    queue<int> q;
    void solve(vector<int> adj[],map<long long,long long> &mp,int s,vector<int> &vis){
        
        q.push(s);
        vis[s] = 1;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int x : adj[curr]){
                
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = 1;
                    }
                    
                    mp[x] += curr;
                  
            }
            
        }
    }
    
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        map<long long,long long> mp;
        
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(adj,mp,i,vis);
            }
            
        }
        
        int maxx = INT_MIN;
        int ans = -1;
        
        
        
        for(auto x : mp){
            if(x.second>maxx){
                maxx = x.second;
                ans = x.first;
            }
        }
        
        return ans;
        
    }
};