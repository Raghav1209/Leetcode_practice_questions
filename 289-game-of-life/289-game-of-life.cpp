class Solution {
public:
    
    int liveornot(vector<vector<int>> &temp,int i,int j,int m,int n){
        
        
        int lives = 0;
        
        if(i>0){
            if(temp[i-1][j]==1){
                lives++;
            }
        }
        
        if(j>0){
            if(temp[i][j-1]==1){
                lives++;
            }
        }
        
        if(i<m-1){
            if(temp[i+1][j]==1){
                lives++;
            }
        }
        
        if(j<n-1){
            if(temp[i][j+1]==1){
                lives++;
            }
        }
        
        if(i>0 && j>0){
            if(temp[i-1][j-1]==1){
                lives++;
            }
            
        }
        
         if(i<m-1 && j<n-1){
            if(temp[i+1][j+1]==1){
                lives++;
            }
        }
        
        if(i>0 && j<n-1){
            if(temp[i-1][j+1]==1){
                lives++;
            }
        }
        
        if(i<m-1 && j>0){
            if(temp[i+1][j-1]==1){
                lives++;
            }
        }
        
        return lives;
        
        
        
        
        
    }
    
    void gameOfLife(vector<vector<int>>& arr) {
        
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> temp = arr;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int ans = liveornot(temp,i,j,m,n);
                
               if(arr[i][j]==0){
                   if(ans==3){
                       arr[i][j] = 1;
                   }
               }else{
                   if(ans<2 || ans>3){
                       arr[i][j] = 0;
                   }
               }
               
            }
        }
        
    }
};