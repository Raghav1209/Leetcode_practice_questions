class Solution {
public:
    
    int solve(vector<int> &v,int i,vector<int> &memo){
        
        if(memo[i]==-1){
        
        if(i>=v.size()){
            return 0;
        }
        
        int currSum = v[i];
        int currVal = v[i];
        int index = i+1;
        
        while(index<v.size() && currVal==v[index]){
            
            currSum += v[index];
            index++;
            
        }
        
        while(index<v.size() && currVal+1 == v[index]){
            
            index++;
            
        }
        
        // memo[i] = currSum;
            
        memo[i] =  max(currSum + solve(v,index,memo),solve(v,i+1,memo));
        return memo[i];
        }
        else{
            return memo[i];
        }
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        // int maxx = max(nums.begin(),nums.end());
        // vector<int> memo(maxx+1,0);
        
        if(n==1){
            return nums[0];
        }
        
        sort(nums.begin(),nums.end());
        
        vector<int> memo(n+1,-1);
        
        return solve(nums,0,memo);
        
        
    }
};