class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        vector<int> ans;
        
        if(nums.size()==1){
             ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        
        int count1 = 0;
        int count2 = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<=nums.size()-1;){
            
            if(i==nums.size()-1){
                count2++;
                break;
            }
            
            if(nums[i]==nums[i+1]){
                count1++;
                i = i+2;
            }else{
                count2++;
                i++;
            }
        }
        
        ans.push_back(count1);
        ans.push_back(count2);
        return ans;
    }
    
    
};