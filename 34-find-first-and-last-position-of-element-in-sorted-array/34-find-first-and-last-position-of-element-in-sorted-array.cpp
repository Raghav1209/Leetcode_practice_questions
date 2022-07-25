class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> :: iterator it,lower,upper;
        
        it = find(nums.begin(),nums.end(),target);
        
        if(it!=nums.end()){
            lower = lower_bound(nums.begin(),nums.end(),target);
            upper = upper_bound(nums.begin(),nums.end(),target);
            cout<<lower-nums.begin()<<endl;
            cout<<upper-nums.begin()-1<<endl;
            ans.push_back(lower-nums.begin());
            ans.push_back(upper-nums.begin()-1);
        }else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        
        return ans;
        
    }
};