class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int gc = numsDivide[0];
        
        for(int i=1;i<numsDivide.size();i++){
            gc = __gcd(gc,numsDivide[i]);
        }
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        int count = 0;
        
        for(auto x : mp){
            
            if(gc%x.first==0){
                return count;
            }else{
                count += x.second;
            }
            
        }
        
        return -1;
        
    }
};