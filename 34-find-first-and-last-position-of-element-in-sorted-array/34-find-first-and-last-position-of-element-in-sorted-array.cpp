class Solution {
public:
    
    int binary(vector<int> &nums,int target,int low,int high){
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
            
        }
        
        return -1;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        int pos = binary(nums,target,0,nums.size()-1);
        int first_occur = pos;
        int last_occur = pos;
        
        if(pos!=-1){
            
            if(first_occur!=0){
                while(first_occur>0 && nums[first_occur]==nums[first_occur-1]){
                    first_occur--;
                }
                ans[0] = first_occur;
            }else{
                ans[0] = 0;
            }
            
            
            if(last_occur!=nums.size()-1){
                while(last_occur<nums.size()-1 && nums[last_occur]==nums[last_occur+1]){
                    last_occur++;
                }
                ans[1] = last_occur;
            }else{
                ans[1] = nums.size()-1;
            }
            
            
        }
        
        return ans;
        
    }
};