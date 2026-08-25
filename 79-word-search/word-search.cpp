class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(0, i, j, board, word)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(
        int idx, int r, int c, 
        vector<vector<char>>& board, 
        string word
    ) {
        if (idx == word.size()) return true;

        if (r < 0 or c < 0 or 
            r >= board.size() or c >= board[0].size() or
            board[r][c] != word[idx]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(idx + 1, r + 1, c, board, word) or
                        dfs(idx + 1, r - 1, c, board, word) or
                        dfs(idx + 1, r, c + 1, board, word) or
                        dfs(idx + 1, r, c - 1, board, word);

        board[r][c] = temp;
        return found;
    }
};