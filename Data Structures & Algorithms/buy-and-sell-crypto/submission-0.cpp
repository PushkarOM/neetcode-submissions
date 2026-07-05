class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0]; // assuming we buy at the first day itself
        int cost = 0;
        int profit = 0; // starting with profit 0

        for(auto it : prices){
            cost = it - buyPrice;
            profit = max(cost, profit);
            buyPrice = min(buyPrice, it);
        }

        return profit;
    }
};
