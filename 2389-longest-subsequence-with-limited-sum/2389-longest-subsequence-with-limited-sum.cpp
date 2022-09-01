class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int count,target;
        for(int i=0;i<queries.size();i++){
            target = queries[i];
            count = 0;
            // sum = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=target){
                    target -= nums[j];
                    // sum += nums[i];
                    count++;
                }
                if(target<=0){
                    break;
                }
            }
            ans.push_back(count);
        }
        
        return ans;
        
    }
};