class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ret++;
                }
            }
        }

        return ret;
    }

private:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 or c < 0 or 
            r >= grid.size() or c >= grid[0].size() or 
            grid[r][c] == '0') return;
            
        grid[r][c] = '0';

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
};