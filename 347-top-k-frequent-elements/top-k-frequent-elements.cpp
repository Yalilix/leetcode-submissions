class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> count;

        for (auto num : nums) {
            count[num]++;
        }

        vector<vector<int>> freq(n + 1);
        for (auto [k, v] : count) {
            freq[v].push_back(k);
        }

        vector<int> ret;

        for (int i = n; i >= 0; i--) {
            for (auto f : freq[i]) {
                if (k) {
                    ret.push_back(f);
                    k--;
                }
            }
        }

        return ret;
    }
};