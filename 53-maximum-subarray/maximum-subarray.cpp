class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ret = INT_MIN;

        for (auto n : nums) {
            sum += n;
            ret = max(ret, sum);
            if (sum < 0) sum = 0;
        }

        return ret;
    }
};