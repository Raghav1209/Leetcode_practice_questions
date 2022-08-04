class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        // int i;
        // for(i=0;i<nums.size();i++)
        // {
        //     if(nums[i] == 0)
        //     {
        //         int j = i+1;
        //         while(j<nums.size() && nums[j]==0){
        //             j++;
        //         }
        //         if(j<nums.size()){
        //             swap(nums[i],nums[j]);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        
        int i = 0;
        int j = 1;
        
        while(j<nums.size()){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else if(nums[i]==0 && nums[i]==0){
                j++;
            }else{
                i++;
                j++;
            }
        }
        
    }
};