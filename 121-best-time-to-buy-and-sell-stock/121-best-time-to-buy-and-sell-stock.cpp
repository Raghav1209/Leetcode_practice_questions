class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int maxx = 0;
        // for(int i=0;i<n-1;){
        //     if(prices[i]<prices[i+1]){
        //         int j = i+1;
        //         while(j<n){
        //             if(prices[j]>prices[i]){
        //                 int profit = prices[j]-prices[i];
        //                 maxx = max(maxx,profit);
        //                 j++;
        //             }else{
        //                 i=j-1;
        //                 break;
        //             }
        //         }
        //     }
        //     i++;
        // }
        int low_price=INT_MAX;
        int profit = 0;
        int max_profit = 0;
        for(int i=0;i<n;i++){
            if(prices[i]<low_price){
                low_price=prices[i];
            }
            profit = prices[i]-low_price;
            if(profit>max_profit){
                max_profit=profit;
            }
        }
        return max_profit;
    }
};