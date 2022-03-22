class Solution {
public:
    string getSmallestString(int n, int k) {
        
       string str(n,'a');
       k -= n;
        
        while(k>0){
            
            str[n-1] += min(25,k);
            n--;
            k -= min(25,k);
            
                
        }
        
        return str;
        
    }
};