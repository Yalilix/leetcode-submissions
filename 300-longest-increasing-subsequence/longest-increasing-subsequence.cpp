class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[1] = 1;
        int ret = dp[1];

        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > 0; j--) {
                if (nums[j - 1] < nums[i - 1]) dp[i] = max(dp[j], dp[i]);
            }
            dp[i] += 1;
            ret = max(dp[i], ret);
        }

        return ret;
    }
};