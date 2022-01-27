class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return true;
        }
        
        if(nums[0]==0){
            return false;
        }
        int maxx=nums[0];
        int step=nums[0];
        
        for(int i=1;i<n-1;i++){
            maxx=max(i+nums[i],maxx);
            step--;
            if(step==0){
                if(i>=maxx){
                    return false;
                }
                step=maxx-i;
            }
        }
        return true;
    }
};