class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        int flag;
        while(nums.size()!=1){
            vector<int> v;
            flag = 1;
            for(int i=0;i<nums.size();i=i+2){

                if(flag){
                    v.push_back(min(nums[i],nums[i+1]));
                }else{
                    v.push_back(max(nums[i],nums[i+1]));
                }

                flag = !flag;

            }
            nums = v;
        }
        return nums[0];
    }
};