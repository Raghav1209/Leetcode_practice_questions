class Solution {
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isValid(int idx,int lim){
        if(idx>=0 && idx<lim){
            return true;
        }else{
            return false;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        queue<pair<int,int>> q;
        // vector<vector<bool>> vis(n,vector<bool>(m,false));
        int time = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 || grid[i][j]==2){
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }
                    total++;
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            
            count += sz;
            
            // cout<<count<<" ";
            
            for(int i=0;i<sz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int ii = x + dx[k];
                    int jj = y + dy[k];
                    
                    if(isValid(ii,n) && isValid(jj,m)){
                        if(grid[ii][jj]==1){
                            grid[ii][jj] = 2;
                            q.push({ii,jj});
                        }
                    }
                    
                }
                

            }
            
            // if(!q.empty()){
            //     time++;
            // }
              
            if(count!=total){
                time++;
            }
                
            
        }
        
        if(count==total){
            return time;
        }else{
            return -1;
        }
        
        
    }
};