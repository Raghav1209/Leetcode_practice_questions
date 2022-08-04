class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        int g = __gcd(p,q);
        // cout<<g;
        p = p/g;
        q = q/g;
        
        if(p%2==0){
            return 2;
        }else if(p%2==1){
            if(q%2==0){
                return 0;
            }else{
                return 1;
            }
        }
        
        return 0;
        
    }
};