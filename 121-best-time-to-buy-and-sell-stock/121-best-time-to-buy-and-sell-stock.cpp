class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         int minbuysofar = prices[0];
//         int profit = 0;
//         int max_profit = 0;
        
//         for(int i=0;i<prices.size();i++){
//             minbuysofar = min(minbuysofar,prices[i]);
//             profit = prices[i] - minbuysofar;
//             max_profit = max(max_profit,profit);
//         }
//         return max_profit;
        
         int n = prices.size();
        int maxx = 0;
        for(int i=0;i<n-1;){
            if(prices[i]<prices[i+1]){
                int j = i+1;
                while(j<n){
                    if(prices[j]>prices[i]){
                        int profit = prices[j]-prices[i];
                        maxx = max(maxx,profit);
                        j++;
                    }else{
                        i=j-1;
                        break;
                    }
                }
            }
            i++;
        }
        return maxx;
        
    }
};