class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minbuysofar = prices[0];
        int profit = 0;
        int max_profit = 0;
        
        for(int i=0;i<prices.size();i++){
            minbuysofar = min(minbuysofar,prices[i]);
            profit = prices[i] - minbuysofar;
            max_profit = max(max_profit,profit);
        }
        return max_profit;
        
    }
};