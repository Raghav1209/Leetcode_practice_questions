class Solution {
public:
    
    void solve(int i,int j,vector<vector<int>> &mat){
        vector<int> v;
        int di = i;
        int dj = j;
        
        while(di<mat.size() && dj<mat[0].size()){
            v.push_back(mat[di][dj]);
            di++;
            dj++;
        }
        
        sort(v.begin(),v.end());
        int k = 0;
        while(i<mat.size() && j<mat[0].size()){
            mat[i][j] = v[k];
            i++;
            j++;
            k++;
        }
        
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        for(int i=0;i<mat[0].size();i++){
            solve(0,i,mat);
        }
        
        for(int i=0;i<mat.size();i++){
            solve(i,0,mat);
        }
        
        return mat;
        
    }
};