class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       
        if(nums1.size()<nums2.size()){
            swap(nums1,nums2);
        }
    
        int ans = 0;
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> dp(n+1,0);
        
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(nums1[j]==nums2[i]){
                    dp[j+1] = 1+dp[j];
                }else{
                    dp[j+1] = 0;
                }
                
                ans = max(ans,dp[j+1]);
                
            }
        }
        
        return ans;
       
    }
};