class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int ret = 0;
        int end = INT_MIN;

        for (auto& interval : intervals) {
            int s = interval[0];
            int e = interval[1];

            if (s < end) {
                ret++;
            } else {
                end = e;
            }
        }

        return ret;
    }
};