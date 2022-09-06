class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int left = 0;
        
        int maxx = INT_MIN;
        
        int andd = 0;
        
        int curr_size = 0;
        
        for(int right=0;right<nums.size();right++){
            
            while(left<=right && (andd & nums[right])!=0){
                andd = andd^nums[left];
                left++;
            }
            
            int curr_size = (right-left+1);
            
            maxx = max(maxx,curr_size);
            
            andd = andd | nums[right];
            
        }
        
        return maxx;
        
    }
};