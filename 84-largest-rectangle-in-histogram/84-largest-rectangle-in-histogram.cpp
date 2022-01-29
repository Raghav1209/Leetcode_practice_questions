class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;
//         vector<int> left(n);
//         vector<int> right(n);
//         left[0]=-1;
//         right[n-1]=n;
//         int prev;
//         for(int i=1;i<n;i++){
//             prev = i-1;
//             while(prev>=0 && heights[prev]>=heights[i]){
//                 prev=left[prev];
//             }
//             left[i] = prev;
//         }
        
//         for(int i=n-2;i>=0;i--){
//             prev=i+1;
//             while(prev<n && heights[prev]>=heights[i]){
//                 prev=right[prev];
//             }
//             right[i]=prev;
//         }
        
//         for(int i=0;i<n;i++){
//             int width = right[i]-left[i]-1;
//             maxArea = max(maxArea,heights[i]*width);
//         }
//         return maxArea;
        
        int n = heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<=n;i++){
            int currHeight = i==n ? 0 : heights[i];
            while(!st.empty() && currHeight<heights[st.top()]){
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : (i-st.top()-1);
                int area = heights[top]*width;
                maxArea = max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
        
    }
    
};