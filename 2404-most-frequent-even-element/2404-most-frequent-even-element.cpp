class Solution {
public:

    
    int mostFrequentEven(vector<int>& nums) {
        
        // priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
            
        }
        
        int maxx = INT_MIN;
        int ans = -1;
        
        for(auto x : mp){
            if(x.second>maxx){
                maxx = x.second;
                ans = x.first;
            }else if(x.second==maxx){
                ans = min(ans,x.first);
            }
        }
        
        return ans;
        
    }
};