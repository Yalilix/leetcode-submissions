class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        unordered_set<string> hs(wordDict.begin(), wordDict.end());

        for (int i = n - 1; i > -1; i--) {
            for (string w : wordDict) {
                if (i + w.size() <= n) {
                    string cur = s.substr(i, w.size());
                    if (cur == w) {
                        dp[i] = dp[i + w.size()];
                    }
                } 
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};