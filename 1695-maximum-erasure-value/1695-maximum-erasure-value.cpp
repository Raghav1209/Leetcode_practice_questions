class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_set<int> s;
        int sum = 0;
        int maxx = INT_MIN;
        int j=0;
        int i=0;
        while(j<nums.size()){
            
            while(s.find(nums[j])!=s.end()){
                sum -= nums[i];
                s.erase(nums[i]);
                i++;
            }
            s.insert(nums[j]);
            sum += nums[j];
            j++;
            maxx=max(maxx,sum);
            
        }
        
        return maxx;
        
    }
};