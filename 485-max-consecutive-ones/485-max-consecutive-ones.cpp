class Solution {
public:
    
    // int max(int a,int b){
    //     if(a>b){
    //         return a;
    //     }
    //     return b;
    // }
    
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxx = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }else{
                maxx = max(maxx,count);
                count = 0;
            }
        }
        maxx = max(maxx,count);
        return maxx;
        
    }
};