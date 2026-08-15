class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int n = s.size();

        int maxLen = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start = 0, end = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        start = j; end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};