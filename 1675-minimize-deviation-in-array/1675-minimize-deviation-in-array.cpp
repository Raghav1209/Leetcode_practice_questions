class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minn = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                nums[i] *= 2;
            }
             minn = min(minn,nums[i]);
            // pq.push(nums[i]);
        }
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        int diff = INT_MAX;
        
        while(!pq.empty() && pq.top()%2==0){
            int maxx = pq.top();
            pq.pop();
            diff = min(diff,maxx-minn);
            minn = min(maxx/2,minn);
            pq.push(maxx/2);
        }
        
        int res = min(diff,pq.top()-minn);
        return res;
    }
};