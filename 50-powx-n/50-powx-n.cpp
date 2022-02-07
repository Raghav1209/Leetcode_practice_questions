class Solution {
public:
    
 
    
//     double myPowutil(double x,int num){
        
//         if(num==1){
//             return double(x);
//         }
        
//         double res = double((x*myPowutil(x,num-1)));
//         return res;

        
        
        
    
        
//     }
    
    double myPow(double x, int n) {
        
//         if(n==0){
//             return 1;
//         }
        
//         int num = abs(n);
        
        
//         double ans = myPowutil(x,num);
        
//         if(n<0){
//             ans = double(1)/double(ans);
//         }
        
//         return double(ans);
        
        return pow(x,n);
    
        
    }
};