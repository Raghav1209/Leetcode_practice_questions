class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int count = 0;
        if(nums.size()<3){
            return count;
        }
        int j;
       for(int i=0;i<=nums.size()-3;i++){
             int diff = nums[i+1]-nums[i];
           for(j=i+2;j<nums.size();j++){
               
                int new_diff = nums[j]-nums[j-1];
               if(new_diff == diff){
                   count++;
               }else{
                   break;
               }
               
               
           }
           
           // if(j-i+1>=3){
           //     count++;
           // }
           
       }
        return count;
    }
};