class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int seen = n;

        for (int i = 0; i < n; i++) {
            seen ^= i ^ nums[i];
        }

        return seen;
    }
};