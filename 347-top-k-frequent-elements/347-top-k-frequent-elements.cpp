class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        
        
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
     
            
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            
        }
        
        for(auto x : mp){
            pq.push(make_pair(x.second,x.first));
        }
        
        int a=0;
        vector<int> res;
        while(a<k){
            res.push_back(pq.top().second);
            pq.pop();
            a++;
        }
        
        return res;
        
        
    }
};