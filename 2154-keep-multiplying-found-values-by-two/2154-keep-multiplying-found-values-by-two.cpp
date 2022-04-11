class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int h = nums.size()-1;
        int target = original;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid] == target){
                target = 2*nums[mid];
                l = 0;
                h = nums.size()-1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        
        return target;
        
    }
};