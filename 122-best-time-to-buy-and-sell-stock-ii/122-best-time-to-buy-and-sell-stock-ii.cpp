class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        stack<int> st;
        int max_pro = 0;
        st.push(0);
        
        for(int i=1;i<prices.size();i++){
            
            if(prices[st.top()]<prices[i]){
                max_pro += prices[i] - prices[st.top()];
                st.pop();
            }
            
            st.push(i);
            
        }
        
        return max_pro;
        
    }
};