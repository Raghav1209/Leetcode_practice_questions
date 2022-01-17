class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        // cout<<s.size();
        nums.erase(nums.begin(),nums.end());
        for(auto x : s){
            nums.push_back(x);
        }
        return s.size();
    }
};