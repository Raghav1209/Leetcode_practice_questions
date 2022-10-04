class Solution {
public:
    
    void make_pascal(vector<vector<int>> &v,int n){
        
        for(int i=0;i<=n;i++){
            vector<int> vc;
            
            for(int j=0;j<=i;j++){
                if(j==0){
                    vc.push_back(1);
                }else if(j==i){
                    vc.push_back(1);
                }else{
                    int sum = v[i-1][j-1]+v[i-1][j];
                    vc.push_back(sum);
                }
            }
            v.push_back(vc);
        }
        
    }
    
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        make_pascal(v,rowIndex);
        return v[rowIndex];
    }
};