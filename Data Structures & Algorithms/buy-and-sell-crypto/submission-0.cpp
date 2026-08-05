class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = INT_MAX, maxProfit = INT_MIN;
        for (int &p : prices) {
            minBuy = min(minBuy, p);
            maxProfit = max(maxProfit, p - minBuy);
        }
        return maxProfit;
    }
};
