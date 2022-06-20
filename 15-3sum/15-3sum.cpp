class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int k = n-1;
        set<vector<int>> s;
        vector<vector<int>> ans;
        while(k>=0){
            int i =0;
            int j = k-1;
            while(i<j){
                int sum = nums[i]+nums[j];
                if(sum==-(nums[k])){
                    s.insert({nums[i],nums[j],nums[k]});
                    i++;
                    j--;
                }else if(sum<-(nums[k])){
                    i++;
                }else{
                    j--;
                }
            }
            k--;
        }
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
        
    }
};