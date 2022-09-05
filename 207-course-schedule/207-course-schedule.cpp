class Solution {
public:
    
    bool DFS(vector<int> adj[],vector<int> &vis,vector<int> &rect,int s){
        
        vis[s] = 1;
        rect[s] = 1;
        
        for(int v : adj[s]){
            if(!vis[v]){
                if(DFS(adj,vis,rect,v)){
                    return true;
                }
            }else if(rect[v]==true){
                return true;
            }
        }
        
        rect[s] = 0;
        return 0;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int> adj[n];
        
        for(int i=0;i<p.size();i++){
            int d = p[i][1];
            int s = p[i][0];
            
            adj[d].push_back(s);
            
        }
        
        vector<int> vis(n+1,0);
        vector<int> rect(n+1,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(DFS(adj,vis,rect,i)){
                    return false;
                }
            }
        }
        
        return true;
        
    }
};