class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        int j = 1;
        
        while(!pq.empty()){
            if(j==k){
                break;
            }
            pq.pop();
            j++;
        }
        
        return pq.top();
        
    }
};