class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

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
                ret.push_back(f);
                k--;
            }

            if (!k) break;
        }

        return ret;
    }
};