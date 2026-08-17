class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        int end = -1;
        vector<int> cur = {};
        for (const auto& interval : intervals) {
            int s = interval[0];
            int e = interval[1];

            if (s > end) {
                if (cur.size() > 0) {
                    cur.push_back(end);
                    ret.push_back(cur);
                }
                cur = {};
                cur.push_back(s);
            }
            if (e > end) end = e;

            if (&interval == &intervals.back()) {
                cur.push_back(end);
                ret.push_back(cur);
            }
        }

        return ret;
    }
};