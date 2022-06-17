class Solution {
public:
    
    double pow(double x,int n){
        
        if(n==0){
            return 1;
        }
        
        double res = pow(x,n/2);
        
        if(n%2==0){
            
            return res*res;
        }else{
            return x*res*res;
        }
        
    }
    
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        
        int num = abs(n);
       double ans = pow(x,num);
        
        if(n<0){
            return 1/ans;
        }else{
            return ans;
        }
        
    }
};