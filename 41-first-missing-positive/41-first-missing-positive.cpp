class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
//         unordered_set<int> s;
        
//         for(int i=0;i<nums.size();i++){
//             s.insert(nums[i]);
//         }
    
//         int maxx = *max_element(nums.begin(),nums.end());
//         int i;
//         for(i=1;i<=maxx;i++){
//             if(s.find(i)==s.end()){
//                 return i;
//             }
//         }
        
//         return i;
        
        int n = nums.size();
        int i;
        for(i=0;i<n;i++){
            
            if(nums[i]<=0 || nums[i]>n){
                continue;
            }
            
            if(nums[nums[i]-1]==nums[i]){
                continue;
            }else{
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
            
        }
        
        for(i=0;i<n;i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        
        return n+1;
        
    }
};