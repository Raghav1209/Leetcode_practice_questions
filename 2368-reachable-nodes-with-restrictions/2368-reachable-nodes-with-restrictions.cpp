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
        int count = 1;
        while(!q.empty()){
    
            // int k = q.size();
            
            // for(int i=0;i<k;i++){
                int curr = q.front();
                q.pop();


                for(int x : adj[curr]){
                    if(!vis[x]){
                        if(s.find(x)==s.end()){
                            count++;
                            q.push(x);
                            vis[x] = true;
                        }
                    }
                }
            // }
        }
                
        
            
    
        
        return count;
    }
};