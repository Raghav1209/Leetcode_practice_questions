class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<int> pq;
        
        long long sum = 0;
        
        for(int i=0;i<target.size();i++){
            sum += target[i];
            pq.push(target[i]);
        }
        
        while(pq.top()!=1){
            
            sum -= pq.top();
            
            if(sum==0 || sum>pq.top()){
                return false;
            }
            
            int old = pq.top()%sum;
            if(sum!=1 && old==0){
                return false;
            }
            
            pq.pop();
            pq.push(old);
            sum += old;
        }
        
        return true;
        
    }
};