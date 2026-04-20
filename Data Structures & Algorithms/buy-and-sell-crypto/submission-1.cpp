class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.empty()) return 0;

        int minPrice = prices[0];
        int profit = 0;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); ++i) {
            // See if we found a new smallest price;
            minPrice = min(minPrice, prices[i]);
            profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
