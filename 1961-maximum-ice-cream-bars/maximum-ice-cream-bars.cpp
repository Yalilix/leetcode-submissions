class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        long long ret = 0;

        for (auto c : costs) {
            if (coins < c) break;

            ret += 1;
            coins -= c;
        }

        return ret;
    }
};