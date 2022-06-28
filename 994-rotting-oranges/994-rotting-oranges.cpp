class Solution {
public:
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    bool isValid(int idx,int lim){
        if(idx>=0 && idx<lim){
            return true;
        }else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int total = 0;
        int time=0;
        int count=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 || grid[i][j]==2){
                    total++;
                    if(grid[i][j]==2){
                         q.push({i,j});
                    }
                   
                    
                }
            }
        }
        
        
        while(!q.empty()){
            
            int k = q.size();
            count += k;
            
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int i = x+dx[k];
                    int j = y+dy[k];

                    if(isValid(i,grid.size()) && isValid(j,grid[0].size())){
                        if(grid[i][j]==1){
                            grid[i][j] = 2;
                            q.push({i,j});
                        }
                    }

                }
            }
            
            
            if(!q.empty()){
                time++;
            }
            
            
            
            
            
        }
        
        if(total==count){
            return time;
        }else{
            return -1;
        }
        
    }
};