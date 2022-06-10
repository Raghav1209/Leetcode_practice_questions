class Solution {
public:
    
    void solve(vector<int> &nums,int sum,set<vector<int>> &s,vector<int> curr,int index){
        
        // if(index==nums.size()){
        //     return;
        // }
        
        if(sum<0){
            return;
        }
        
        if(sum==0){
            s.insert(curr);
            return;
        }
        
        
        
        for(int i=index;i<nums.size();i++){
            
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            
            if(sum-nums[i]<0){
                break;
            }
            
            curr.push_back(nums[i]);
        
            solve(nums,sum-nums[i],s,curr,i+1);
            
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        set<vector<int>> s;
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                vector<int> vc;
                vc.push_back(nums[i]);
                s.insert(vc);
            }
           
        }
        
        solve(nums,target,s,curr,0);
        
        for(auto x : s){
            ans.push_back(x);
        }
        return ans;
    }
};