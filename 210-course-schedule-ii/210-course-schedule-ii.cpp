class Solution {
public:
    
    void DFS(int s,vector<int> adj[],vector<bool> &vis,stack<int> &st){
        
        vis[s] = true;
        
        for(int v : adj[s]){
            if(!vis[v]){
                DFS(v,adj,vis,st);
            }
        }
        
        st.push(s);
        
    }
    
    bool cycle(vector<int> adj[],vector<bool> &vis,int s,vector<bool> &rect){
        
        vis[s] = true;
        rect[s] = true;
        
        for(int v : adj[s]){
            if(!vis[v]){
                if(cycle(adj,vis,v,rect)==true){
                    return true;
                }
            }else if(rect[v]){
                return true;
            }
        }
        
        rect[s] = false;
        return false;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> vis(numCourses,false);
        vector<bool> rect(numCourses,false);
        vector<int> adj[numCourses];
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<prerequisites.size();i++){
            int source = prerequisites[i][1];
            int des = prerequisites[i][0];
            adj[source].push_back(des);
        }
        
        for(int i=0;i<numCourses;i++){
            if(cycle(adj,vis,i,rect)==true){
                return ans;
            }
        }
        
        vis = vector<bool>(numCourses,false);
        
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
                DFS(i,adj,vis,st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};