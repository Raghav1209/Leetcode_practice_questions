class Solution {
public:
    
    
    int minOperations(vector<int>& nums, int x) {
            
            int n = nums.size();
            int sum = 0;
        
        
        
        int ans = -1;
            for(int i=0;i<n;i++){
                sum += nums[i];
            }
        
        if(x>sum){
            return -1;
        }
        
            sum -= x;
        
            int low=0;
        int high=0;
        int curr_sum=0;
        
        while(high<n){
            curr_sum += nums[high];
            while(curr_sum>sum){
                curr_sum -= nums[low];
                low++;
            }
            
            if(curr_sum==sum){
                ans = max(ans,high-low+1);
            }
            
            high++;
            
        }
        
        if(ans==-1){
            return -1;
        }else{
            return n-ans;
        }
            
    }
        
        
    
};