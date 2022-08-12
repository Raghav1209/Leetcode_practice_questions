class Solution {
public:
    
    int maxCount = -1;
    int count = 0;
    
    int DFS(vector<int> adj[],vector<int> &vis,vector<int> &dfstrack,vector<int> &num,int s){
        
        vis[s] = 1;
        dfstrack[s] = 1;
        count++;
        num[s] = count;
        
        for(int x : adj[s]){
            if(!vis[x]){
                int val = DFS(adj,vis,dfstrack,num,x);
                dfstrack[s] = 0;
                return val;
            }else if(dfstrack[x]==1){
                dfstrack[x] = 0;
                return num[s]-num[x]+1;
            }
        }
        
        dfstrack[s] = 0;
        return 0;
        
    }
    
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> vis(n,0);
        vector<int> dfstrack(n,0);
        vector<int> num(n,0);
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int maxx = DFS(adj,vis,dfstrack,num,i);
                maxCount = max(maxCount,maxx);
                count = 0;
            }
        }
        
        return (maxCount==0) ? -1 : maxCount;
        
        
    }
};