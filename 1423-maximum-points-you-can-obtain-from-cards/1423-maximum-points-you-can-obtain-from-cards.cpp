class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int total = 0;
        int sum = 0;
        int window = n-k;
        int ans;
        
        for(int i=0;i<n;i++){
            total += cardPoints[i];
        }
        
        for(int i=0;i<window;i++){
            sum += cardPoints[i];
        }
        ans = sum;
        
        for(int i=0;i<n-window;i++){
            
            sum -= cardPoints[i];
            sum += cardPoints[i+window];
            ans = min(ans,sum);
            
        }
        
        return total-ans;
    }
        
    
};