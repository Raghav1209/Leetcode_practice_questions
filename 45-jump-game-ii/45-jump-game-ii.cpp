class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        
        if(nums[0]==0){
            return -1;
        }
        
        int jump = 1;
        int steps = nums[0];
        int maxx = nums[0];
        for(int i=1;i<=n;i++){
            if(i==n-1){
                return jump;
            }
            maxx = max(maxx,i+nums[i]);
            steps--;
            if(steps==0){
                jump++;
                if(i>=maxx){
                    return -1;
                }
                steps=maxx-i;
            }
        }
        return jump;
    }
};