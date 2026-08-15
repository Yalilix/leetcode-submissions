class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int l = 0, r = 0;
        int maxProfit = 0;
        while (r <= n) {
            if (prices[r] < prices[l]) {
                r = l;
                l++;
            } else {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            }
            r++;
        }
        return maxProfit;
    }
};