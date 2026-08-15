class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            int cur = nums[m];

            if (target == cur) return m;

            if (cur < target) {
                if (nums[l] <= cur || nums[l] > target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (nums[r] >= cur || nums[r] < target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};