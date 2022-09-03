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
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),false));
        
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            vis[x][y] = true;
            
            for(int k=0;k<4;k++){
                int i = x+dx[k];
                int j = y+dy[k];
                
                if(isValid(i,image.size()) && isValid(j,image[0].size())){
                    
                    if(!vis[i][j] && image[i][j]==image[sr][sc]){
                        image[i][j] = color;
                        q.push({i,j});
                    }
                    
                }
                
                
            }
            
        }
        

         image[sr][sc] = color;
        
       
        
        return image;
        
    }
};