class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            minValue = min(minValue, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minValue);
        }
        return maxProfit;
    }
};
