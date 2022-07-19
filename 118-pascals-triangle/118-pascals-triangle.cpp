class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        
        for(int i=1;i<numRows;i++){
            v.clear();
            for(int j=0;j<=i;j++){
                if(j==0){
                    v.push_back(1);
                }else if(j==i){
                    v.push_back(1);
                }else{
                    int x = ans[i-1][j-1] + ans[i-1][j];
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
        
        
        
        
    }
};