class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n + 2, false);
        dp[n] = true;

        for (int i = n - 1; i > 0; i--) {
            for (int j = 1; j <= nums[i - 1]; j++) {
                if (dp[i] || i + j > n) break;
                dp[i] = dp[i + j];
            }
        }

        return dp[1];
    }
};