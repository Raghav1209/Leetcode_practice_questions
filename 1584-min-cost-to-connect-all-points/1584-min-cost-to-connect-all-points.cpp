class Solution {
public:
    
    int prim(vector<vector<int>> graph,int n){
        int key[n];
        int res = 0;
        fill(key,key+n,INT_MAX);
        key[0]=0;
        bool mset[n];
        
        for(int i=0;i<n;i++){
            mset[i] = false;
        }
        
        for(int count=0;count<n;count++){
            int u = -1;
            for(int i=0;i<n;i++){
                if(!mset[i] && (u==-1 || key[i]<key[u])){
                    u=i;
                }
            }
            
            mset[u] = true;
            res = res + key[u];
            
            for(int v=0;v<n;v++){
                if(graph[u][v]!=0 && !mset[v]){
                    key[v] = min(key[v],graph[u][v]);
                }
            }
        }
        
        return res;
        
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> graph(n, vector<int> (n));;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                // graph[j][i] = graph[i][j];
            }
        }
        
        return prim(graph,n);
        
        // cout<<graph<<endl;
        // return 0;
    }
};