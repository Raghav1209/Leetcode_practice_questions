class KthLargest {
public:
    
    // priority_queue<int> pq;
    // vector<int> nums2;
    // int kk;
    // int kkk;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
           
        }
        
        kk=k;
    
            //  for(int i=0;i<nums.size();i++){
            //     nums2.push_back(nums[i]);
            //  }
            //  kk=k;
            // kkk=k;
        
    }
    
    int add(int val) {
        
        pq.push(val);
        
        if(pq.size()>kk){
            pq.pop();
        }
        
        return pq.top();
        
//         pq = priority_queue <int>();
        
//         for(int i=0;i<nums2.size();i++){
//             pq.push(nums2[i]);
//         }
        
//         pq.push(val);
//         nums2.push_back(val);
        
//         while(kk>1){
//             pq.pop();
//             kk--;
//         }
        
//         kk=kkk;
        
//         return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */