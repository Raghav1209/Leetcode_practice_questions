class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>> v;
        int l = 0;
        int h = nums.size()-1;
        while(l<h){
            v.push_back(make_pair(nums[l],nums[h]));
            l++;
            h--;
        }
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
        int max_pair_sum = INT_MIN;
        
        for(int i=0;i<v.size();i++){
            int x = v[i].first + v[i].second;
            max_pair_sum = max(max_pair_sum,x);
        }
        
        return max_pair_sum;
        
    }
};