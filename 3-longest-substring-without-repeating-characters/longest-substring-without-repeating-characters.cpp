class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();

        set<int> seen;
        int ret = 0;

        while (r < n) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }

            ret = max(ret, r - l + 1);
            seen.insert(s[r]);
            r++;
        }

        return ret;
    }
};