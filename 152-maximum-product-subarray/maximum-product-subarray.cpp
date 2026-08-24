class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMin = 1, curMax = 1;
        int ret = nums[0];

        for (auto& n : nums) {
            if (n == 0) {
                curMin = 1; curMax = 1;
            }

            int temp = curMin;
            curMin = min({curMin * n, curMax * n, n});
            curMax = max({temp * n, curMax * n, n});
            ret = max(ret, curMax);
        }

        return ret;
    }
};