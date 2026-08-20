class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ret = nums[0];
        while (l <= r) {
            if (l == r) return min(nums[l], ret);
            int m = (l + r) / 2;
            int cur = nums[m];

            ret = min(cur, ret);
            if (nums[l] < cur) {
                if (nums[l] < nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (cur < nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return ret;
    }
};