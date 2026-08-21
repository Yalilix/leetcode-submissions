class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pac;
        set<pair<int, int>> atl;
        int n = heights.size();
        int m = heights[0].size();

        // left and right
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pac, heights[i][0]);
            dfs(i, m - 1, heights, atl, heights[i][m - 1]);
        }

        // top and bottom
        for (int i = 0; i < m; i++) {
            dfs(0, i, heights, pac, heights[0][i]);
            dfs(n - 1, i, heights, atl, heights[n - 1][i]);
        }

        vector<vector<int>> ret;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (pac.contains({r, c}) and atl.contains({r, c})) {
                    ret.push_back({r, c});
                }
            }
        }
        return ret;
    }
private:
    void dfs(int r, int c, vector<vector<int>>& heights, set<pair<int, int>>& visit, int prevHeight) {
        if (visit.contains({r, c}) or 
            r < 0 or c < 0 or r >= heights.size() or c >= heights[0].size() or 
            heights[r][c] < prevHeight) return;

        visit.insert({r, c});
        dfs(r + 1, c, heights, visit, heights[r][c]);
        dfs(r - 1, c, heights, visit, heights[r][c]);
        dfs(r, c + 1, heights, visit, heights[r][c]);
        dfs(r, c - 1, heights, visit, heights[r][c]);
    }
};