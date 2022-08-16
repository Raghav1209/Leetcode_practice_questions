class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int gc = numsDivide[0];
        
        for(int i=1;i<numsDivide.size();i++){
            gc = __gcd(gc,numsDivide[i]);
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(__gcd(nums[i],gc)==nums[i]){
                return i;
            }
        }
        
        return -1;
        
    }
};