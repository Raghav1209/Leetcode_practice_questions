class Solution {
public:
    
    bool isSafe(int ele,map<int,int> &s){
        
        if(s.find(ele)==s.end()){
            return false;
        }else{
            return true;
        }
        
    }
    
    
    void solve(vector<int> &nums,vector<vector<int>> &operations,int i,map<int,int> &s){
        
        if(i==operations.size()){
            return;
        }
        
        vector<int> vc = operations[i];
        
        if(isSafe(vc[0],s)){
            int x = s[vc[0]];
            swap(nums[s[vc[0]]],vc[1]);
            s[nums[x]]=x;
            solve(nums,operations,i+1,s);
        }
        
    }
    
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        map<int,int> s;
        
        for(int i=0;i<nums.size();i++){
            s[nums[i]]=i;
        }
        
        solve(nums,operations,0,s);
        return nums;
    }
};