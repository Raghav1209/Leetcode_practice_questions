int n = prices.size();
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