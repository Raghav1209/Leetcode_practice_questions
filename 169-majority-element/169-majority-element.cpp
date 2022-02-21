class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
//         int n = nums.size();
//         int x  = n/2;
        
//         unordered_map<int,int> mp;
        
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto a : mp){
//             if(a.second > x){
//                 return a.first;
//             }
//         }
        
//         return -1;
        
        sort(nums.begin(),nums.end());
        
        return nums[nums.size()/2];
        
    }
};