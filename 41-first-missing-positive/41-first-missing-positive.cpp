class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
    
        int maxx = *max_element(nums.begin(),nums.end());
        int i;
        for(i=1;i<=maxx;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        
        return i;
        
    }
};