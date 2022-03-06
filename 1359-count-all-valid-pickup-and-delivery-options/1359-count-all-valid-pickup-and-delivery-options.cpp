class Solution {
public:
    int countOrders(int n) {
        
        int m = n;
        int mod = 1000000007;
        long long ans = 1;
        while(m>0){
            ans *= m;
            m--;
            ans = ans%mod;
        }
        
        int x = 1;
        
        while((2*n-x)>0){
            ans *= (2*n-x);
            x += 2;
            ans = ans%mod;
        }
        
        return ans%mod;
        
    }
};