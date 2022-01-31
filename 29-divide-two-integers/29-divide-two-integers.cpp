class Solution {
public:
    int divide(int dividend, int divisor) {
        long divid = (long)dividend;
        long divis = (long)divisor;
         long x = divid/divis;
        if(x<INT_MIN){
            return INT_MIN;
        }
        if(x>INT_MAX){
            return INT_MAX;
        }
        return x;
    }
};