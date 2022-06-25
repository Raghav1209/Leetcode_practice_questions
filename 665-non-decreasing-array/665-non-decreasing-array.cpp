class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        if(nums.size()==1){
            return true;
        }
        int modify = 0;
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]<nums[i-1]){
                
               
                
                if(modify==1){
                    return false;
                }
                
                                
                modify++;
                
                if(i<2 || nums[i-2]<=nums[i]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
                
            }
            
              
        }
        
        return true;
        
    }
};