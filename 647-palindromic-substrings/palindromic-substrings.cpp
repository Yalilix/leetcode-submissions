class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));

        int ret = 0;
        for (int i = n - 1; i > -1; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 or dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (j - i <= 2) {
                        ret++;
                    } else {
                        if (dp[i + 1][j - 1]) {
                            ret++;
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};