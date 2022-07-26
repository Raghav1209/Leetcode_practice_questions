class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        if(nums[nums.size()-1]!=9){
            nums[nums.size()-1] += 1;
            return nums;
        }else{
            while(n>0 && nums[n-1]==9){
                nums[n-1] = 0;
                n--;
            }
        }
        
        if(n==0){
            nums[0] = 1;
            nums.push_back(0);
        }else{
            nums[n-1] += 1;
        }
        
        
        return nums;
        
    }
};