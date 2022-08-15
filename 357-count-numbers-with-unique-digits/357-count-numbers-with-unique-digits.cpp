class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0){
            return 1;
        }
        
        int ans = 10;
        int start = 9;
        int curr = 9;
        n--;
        while(n && start){
            
            curr *= start;
            start--;
            ans += curr;
            n--;
        }
        
        return ans;
        
    }
};