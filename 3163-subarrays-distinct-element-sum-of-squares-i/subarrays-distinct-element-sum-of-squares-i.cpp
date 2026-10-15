class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                set<int> hs;
                int count = 0;

                for (int k = i; k <= j; k++) {
                    if (!hs.contains(nums[k])) {
                        hs.insert(nums[k]);
                        count++;
                    }
                }

                counts.push_back(count);
            }
        }

        int ret = 0;
        for (auto c : counts) {
            ret += (c * c);
        }

        return ret;
    }
};