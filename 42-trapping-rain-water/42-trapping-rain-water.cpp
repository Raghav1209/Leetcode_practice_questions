class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        int sum = 0;
        maxLeft[0]=height[0];
        maxRight[n-1]=height[n-1];
        
        for(int i=1;i<n;i++){
            maxLeft[i]=max(height[i],maxLeft[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            maxRight[i] = max(height[i],maxRight[i+1]);
        }
        
        for(int i=0;i<n;i++){
            sum += min(maxLeft[i],maxRight[i])-height[i];
        }
        
        return sum;
        
    }
};