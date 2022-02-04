class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int> mp;
        int n = nums.size();
       
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        
        int sum = 0;
        int maxx = 0;
        
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            if(mp.find(sum)!=mp.end()){
                int last_same_sum = mp[sum];
                maxx = max(maxx,i-last_same_sum);
            }else{
                mp[sum] = i;
            }
            
        }
        
        return maxx;
        
        
    }
};