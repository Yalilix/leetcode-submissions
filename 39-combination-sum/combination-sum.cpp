class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(0, cur, ret, 0, target, candidates);
        return ret;
    }

private:
    void dfs(int idx, vector<int> cur, vector<vector<int>>& ret, int sum, int target, vector<int>& candidates) {
        if (sum > target || idx >= candidates.size()) return;

        if (sum == target) {
             ret.push_back(cur);
            return;
        }
        
        int val = candidates[idx];
        cur.push_back(val);
        dfs(idx, cur, ret, sum + val, target, candidates);
        cur.pop_back();
        dfs(idx + 1, cur, ret, sum, target, candidates);
        return;
    }
};