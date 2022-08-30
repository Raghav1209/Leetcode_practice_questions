class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> count(nums.size()+1,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        
        for(int i=0;i<count.size();i++){
            if(count[i]==2){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};