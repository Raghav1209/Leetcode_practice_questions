class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            
        }
        
        queue<int> q;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto v : adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
            
        }
        
        if(res.size()==n){
            return true;
        }else{
            return false;
        }
        
        
        
        
    }
};