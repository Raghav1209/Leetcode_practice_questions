class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<int> adj[n];
        unordered_set<int> s(begin(r),end(r));
        for(int i=0;i<edges.size();i++){
            int s = edges[i][0];
            int d = edges[i][1];
            
            adj[s].push_back(d);
            adj[d].push_back(s);
            
        }
        
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int count = 0;
        while(!q.empty()){
    
            int curr = q.front();
            q.pop();
            
            if(s.find(curr)!=s.end()){
                continue;
            }
            
            count++;
            
            for(int x : adj[curr]){
                if(!vis[x]){
                    
                    q.push(x);
                    vis[x] = true;
                    
                }
            }
        }
                
        
            
    
        
        return count;
    }
};