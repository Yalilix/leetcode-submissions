class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int curMin = 1, curMax = 1;
        int ret = 0;

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