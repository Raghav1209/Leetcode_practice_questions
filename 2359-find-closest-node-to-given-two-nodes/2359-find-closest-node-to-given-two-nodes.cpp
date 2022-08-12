class Solution {
public:
    
    void DFS(vector<int> adj[],int s,vector<int> &res,vector<int> &vis){
        
        vis[s] = 1;
        // res[s] = 0;
        
        for(int i : adj[s]){
            if(i==-1){
                continue;
            }
            
            if(!vis[i]){
                res[i] = max(res[i],res[s]+1);
                DFS(adj,i,res,vis);
            }
            
        }
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<int> res1(n,-1);
        vector<int> res2(n,-1);
        int ans=-1;
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }
        
        vector<int> vis(n,0);
        res1[node1] = 0;
        DFS(adj,node1,res1,vis);
            
        vis = vector<int>(n,0);
        res2[node2] = 0;
        DFS(adj,node2,res2,vis);
        
        // for(int i=0;i<n;i++){
        //     cout<<res1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<res2[i]<<" ";
        // }
        int prev_maxx = INT_MAX;  
        for(int i=n-1;i>=0;i--){
            if(res1[i]==-1 || res2[i]==-1){
                continue;
            }else{
                int maxx = max(res1[i],res2[i]);
                if(maxx<=prev_maxx){
                    prev_maxx = maxx;
                    ans = i;
                }
                // ans = i;
            }
        }
        
        return ans;
        
    }
};