class Solution {
public:
    
 
    
    double myPowutil(double x,int num){
        
        if(num==0){
            return 1;
        }
        
        double res = myPowutil(x,num/2);
        
        if(num%2==0){
            return res*res;
        }else{
           return  x*res*res;
        }

        
        
        
    
        
    }
    
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        
        int num = abs(n);
        
        
        double ans = myPowutil(x,num);
        
        if(n<0){
            ans = double(1)/double(ans);
        }
        
        return double(ans);
        
        // return pow(x,n);
    
        
    }
};