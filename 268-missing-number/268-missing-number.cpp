class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            
        }
        int maxx,minn,i;
         maxx = *max_element(nums.begin(),nums.end());
         // minn = *min_element(nums.begin(),nums.end());
        for(i=0;i<maxx;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        
        return i+1;
        
    }
};