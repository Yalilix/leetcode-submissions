class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hm;
        for (auto n : nums) {
            hm[n]++;
        }   

        vector<vector<int>> freq(nums.size() + 1);
        for (auto [key, val] : hm) {
            freq[val].push_back(key);
        }

        vector<int> ret;
        for (int i = nums.size(); i > 0; i--) {
            for (auto key : freq[i]) {
                ret.push_back(key);
                k--;
            }
            if (k == 0) return ret; 
        }

        return ret;
    }
};