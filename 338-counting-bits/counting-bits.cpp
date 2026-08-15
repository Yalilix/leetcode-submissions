class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;

        for (int i = 0; i <= n; i++) {
            int j = i;
            int count = 0;
            while (j > 0) {
                if (j & 1) count++;
                j >>= 1;
            }

            ret.push_back(count);
        }

        return ret;
    }
};