class Solution {
public:
    
    // static bool sortbysec(const vector<int>& v1,const vector<int>& v2){
    //     return v1[1]<v2[1];
    // }
    
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        
        sort(interval.begin(),interval.end()); 
        
        vector<vector<int>> res;
        
        res.push_back(interval[0]);
        int j = 0;
        for(int i=1;i<interval.size();i++){
            if(res[j][1]>=interval[i][0]){
                res[j][1] = max(interval[i][1],res[j][1]);
            }else{
                res.push_back(interval[i]);
                j++;
            }
        }
        
        return res;
        
        
    }
};