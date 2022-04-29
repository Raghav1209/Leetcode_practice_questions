class Solution {
public:
    
    bool BFS(vector<vector<int>> graph,bool visited[],int s){
        
        queue<int> q;
        q.push(s);
        visited[s] = true;
        vector<int> color(graph.size(),-1);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vector<int> x = graph[u];
            if(color[u]==-1){
                color[u] = 1;
            }
            
           
            for(int i=0;i<x.size();i++){
                if(visited[x[i]]==false){
                    q.push(x[i]);
                    visited[x[i]] = true;
                }

                if(color[x[i]]==-1){
                    color[x[i]] = !color[u];
                }else{
                    if(color[x[i]] != !color[u]){
                        return false;
                    }
                }
            }

            
        }
        
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();
        bool visited[V];
        bool ans = true;
        
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        
        
        
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                ans = BFS(graph,visited,i);
                if(!ans)
                    return false;
            }
           
        }
       return true;
    }
};