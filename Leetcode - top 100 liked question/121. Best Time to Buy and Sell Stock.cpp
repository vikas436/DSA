class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int profit = 0, pre = prices[0];
        for(int i=1;i<prices.size();i++) {
            profit = max(profit, prices[i]-pre);
            if(pre>prices[i]) pre = prices[i];
        }
        return profit;
    }
};
