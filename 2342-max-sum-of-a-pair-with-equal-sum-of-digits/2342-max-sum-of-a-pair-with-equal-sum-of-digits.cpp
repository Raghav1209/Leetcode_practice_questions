class Solution {
public:
    
     int cal_sum(int num){
        int sum = 0;
        while(num){
            sum += (num%10);
            num /= 10;
        }
        
        return sum;
        
    }
    
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<nums.size();i++){
            
            int x = cal_sum(nums[i]);
            
            mp[x].push_back(nums[i]);
            
        }
        int maxx = INT_MIN;
        for(auto x : mp){
            vector<int> vc = x.second;
            
            if(vc.size()>1){
                sort(vc.begin(),vc.end(),greater<int>());
                maxx = max(maxx,vc[0]+vc[1]);
            }
        }
        
        if(maxx==INT_MIN){
            return -1;
        }else{
            return maxx;
        }
        
    }
};