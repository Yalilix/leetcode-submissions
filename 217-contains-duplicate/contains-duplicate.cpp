class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen = set(nums.begin(), nums.end());
        return seen.size() != nums.size();
    }
};