class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        vector<vector<int>> ret;
        int n = intervals.size();

        if (newInterval[1] < intervals[0][0]) {
            ret.push_back(newInterval);
            for (int i = 0; i < n; i++) {
                ret.push_back(intervals[i]);
            }
            return ret;
        }

        bool added = false;
        for (int i = 0; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (!added && s > newInterval[1]) {
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                added = true;
                continue;
            }

            if (!added && e >= newInterval[0] ) {
                newInterval[0] = min(s, newInterval[0]);
                newInterval[1] = max(e, newInterval[1]);
                if (i + 1 >= n) {
                    ret.push_back(newInterval);
                    break;
                }
                for (int j = i + 1; j < n; j++) {
                    int s = intervals[j][0];
                    int e = intervals[j][1];
                    if (e > newInterval[1] && s > newInterval[1]) {
                        ret.push_back(newInterval);
                        ret.push_back(intervals[j]);
                        i = j;
                        added = true;
                        break;
                    } else {
                        newInterval[1] = max(e, newInterval[1]);
                    }
                }
            } else {
                ret.push_back(intervals[i]);
            }

            if (i + 1 >= n && !added) ret.push_back(newInterval);
        }
        return ret;
    }
};