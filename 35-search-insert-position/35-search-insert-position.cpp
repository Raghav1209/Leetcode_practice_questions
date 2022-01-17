class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==1 && target==nums[0]){
            return 0;
        }
        //  if(target==0){
        //     return 0;
        // }
        int pos;
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                h = mid-1;
                pos = mid;
            }else{
                l = mid+1;
                pos = l;
            }
        }
        
        
        return pos;
    }
};