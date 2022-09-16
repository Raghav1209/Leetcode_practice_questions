class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        
        int n = c.size();
        
        int window = n-k;
        int sum = 0;
        int sum1 = 0;
        int min_sum = INT_MAX;
        
        for(int i=0;i<c.size();i++){
            sum1 += c[i];
        }
        
        for(int i=0;i<window;i++){
            sum += c[i];
        }
        
        min_sum = min(sum,min_sum);
        
        for(int i=1;i<=n-window;i++){
            
            sum += c[i+window-1];
            sum -= c[i-1];
            
            min_sum = min(sum,min_sum);
            
        }
        
        return sum1-min_sum;
        
        
        
    }
};