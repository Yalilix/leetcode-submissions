class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string ret = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string cur = "";
                int l = i, r = j;

                while (l <= r) {
                    if (s[l] != s[r]) break;
                    l++; r--;
                }

                if (l > r) {
                    cur = s.substr(i, j - i + 1);
                }

                if (cur.size() > maxLen) {
                    ret = cur;
                    maxLen = cur.size();
                }
            }
        }

        return ret;
    }
};