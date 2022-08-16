class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();
        int size = nums.size();
        int sz = nums[0].size();
        vector<int> res;
        
        for(int i=0;i<n;i++){
            vector<pair<string,int>> vc;
            
            for(int j=0;j<size;j++)
            {
                string str = nums[j].substr(sz-queries[i][1]);
                vc.push_back({str,j});
            
            }
            
            
            sort(vc.begin(),vc.end());
            res.push_back(vc[queries[i][0]-1].second);
        }
        
        return res;
        
    }
};