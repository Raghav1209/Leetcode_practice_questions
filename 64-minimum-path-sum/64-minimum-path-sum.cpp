class Solution {
public:
    
    bool isValid(int index,int lim){
        return (index>=0 && index<lim);
    }
    
    const int inf = 1e6+1;
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> dis(m,vector<int>(n,inf));
        dis[0][0] = grid[0][0];
        pq.push({(-1)*dis[0][0],{0,0}});
        
        while(!pq.empty()){
            
            int distance = (-1)*pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x==m-1 && y==n-1){
                return distance;
            }
            
            for(int k=0;k<2;k++){
                int i = x+dx[k];
                int j = y+dy[k];
                
                if(isValid(i,m) && isValid(j,n)){
                    int sum = distance + grid[i][j];
                    if(sum < dis[i][j]){
                        dis[i][j] = sum;
                        pq.push({(-1)*dis[i][j],{i,j}});
                    }
                }   
            } 
        }
        return -1;
    }
};