class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hm;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (hm.contains(diff)) return {hm[diff], i};

            hm[nums[i]] = i;
        }
        return {};
    }
};