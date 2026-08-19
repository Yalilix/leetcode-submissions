class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        int ret = 0;
        for (int n : numSet) {
            if (numSet.contains(n - 1)) continue;

            int length = 1;
            while (numSet.contains(n + length)) {
                length++;
            }
            ret = max(ret, length);
        }

        return ret;
    }
};