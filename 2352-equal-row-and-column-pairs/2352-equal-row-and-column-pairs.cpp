class Solution {
public:
    
    void take_trans(vector<vector<int>> &trans){
        
        for(int i=0;i<trans.size();i++){
            for(int j=i;j<trans[0].size();j++){
                
                swap(trans[i][j],trans[j][i]);
                
            }
        }
        
    }
    
    int equalPairs(vector<vector<int>>& grid) {
        
        vector<vector<int>> trans = grid;
        int count = 0;
        take_trans(trans);
        
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
                
//                 cout<<trans[i][j]<<" ";
                
//             }
//             cout<<endl;
//         }
        
        for(auto vc1 : grid){
            // vector<int> vc1 = grid[i];
            for(auto vc2 : trans){
                // vector<int> vc2 = trans[i];
                if(vc1==vc2){
                    count++;
                }
            }
        }
        
        return count;
        
    }
};