class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        // vector<int> v = nums;
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        int count = 0;
       
        while(i<nums.size()){
            int x = nums[i];
            if(x!=0){
                for(int j=i;j<nums.size();j++){
                    if(nums[j]>0){
                        nums[j] -= x;
                    }
                }
                count++;
            }
            i++;
        }
            
        return count;
        
    }
};