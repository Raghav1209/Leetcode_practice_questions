class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        deque<int> q {1,2,3,4,5,6,7,8,9};
        
        while(--n){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop_front();
                
                for(int j=0;j<=9;j++){
                    
                    if(abs(curr%10-j)==k){
                        q.push_back(curr*10+j);
                    }
                    
                }
                
            }
            
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop_front();
        }
        
        return ans;
        
    }
};