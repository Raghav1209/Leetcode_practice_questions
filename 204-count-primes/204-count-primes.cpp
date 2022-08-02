class Solution {
public:
    int countPrimes(int n) {
        
        
        if(n==0 || n==1){
            return 0;
        }
        
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        
        for(int i=2;i*i<n;i++){
            if(prime[i]){
                for(int j=2;i*j<=n;j++){
                    prime[i*j] = false;
                }
            }
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++){
            if(prime[i]){
                res++;
            }
        }
        
        return res;
        
    }
};