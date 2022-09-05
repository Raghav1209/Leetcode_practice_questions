class Solution {
public:
    
    void DFS(vector<int> adj[],vector<int> &vis,int s,stack<int> &st){
        
        vis[s] = 1;
        
        for(int v : adj[s]){
            if(!vis[v]){
                DFS(adj,vis,v,st);
            }
        }
        
        st.push(s);
    }
    
    bool checkCycle(vector<int> adj[],vector<int> &vis,vector<int> &rect,int s){
        
        vis[s] = 1;
        rect[s] = 1;
        
        for(int v : adj[s]){
            if(!vis[v]){
                if(checkCycle(adj,vis,rect,v)){
                    return true;
                }
            }else if(rect[v]==true){
                return true;
            }
        }
        
        rect[s] = 0;
        return false;
        
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        vector<int> adj[n];
        
        vector<int> vis(n,0);
        vector<int> rect(n,0);
        
        for(int i=0;i<p.size();i++){
            int s = p[i][0];
            int d = p[i][1];
            adj[d].push_back(s);
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(checkCycle(adj,vis,rect,i)){
                    return ans;
                }
            }
        }
        
       vis = vector<int>(n,0);
        
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(adj,vis,i,st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};