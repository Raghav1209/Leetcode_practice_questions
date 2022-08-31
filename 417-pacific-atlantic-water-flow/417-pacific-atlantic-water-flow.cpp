class Solution {
public:
    
    void DFS(vector<vector<int>> h,vector<vector<int>> &vis,int i,int j){
        
        vis[i][j] = true;
        
        if(i-1>=0 && !vis[i-1][j] && h[i-1][j]>=h[i][j]){
            DFS(h,vis,i-1,j);
        }
        
        if(i+1<h.size() && !vis[i+1][j] && h[i+1][j]>=h[i][j]){
            DFS(h,vis,i+1,j);
        }
        
        if(j-1>=0 && !vis[i][j-1] && h[i][j-1]>=h[i][j]){
            DFS(h,vis,i,j-1);
        }
        
        if(j+1<h[0].size() && !vis[i][j+1] && h[i][j+1]>=h[i][j]){
            DFS(h,vis,i,j+1);
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        vector<vector<int>> ans;
        vector<vector<int>> pac(h.size(),vector<int>(h[0].size()));
        vector<vector<int>> atlan(h.size(),vector<int>(h[0].size()));
        
        for(int i=0;i<h.size();i++){
            DFS(h,pac,i,0);
            DFS(h,atlan,i,h[0].size()-1);
        }
        
        for(int i=0;i<h[0].size();i++){
            DFS(h,pac,0,i);
            DFS(h,atlan,h.size()-1,i);
        }
        
        for(int i=0;i<h.size();i++){
            for(int j=0;j<h[0].size();j++){
                if(pac[i][j] && atlan[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;

    }
};