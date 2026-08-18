class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(int r, int c, int i, vector<vector<char>>& board, string&word) {
        if (i == word.size()) return true;

        if (r < 0 || c < 0 || 
            r >= board.size() || c >= board[0].size() ||
            word[i] != board[r][c]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = 
            dfs(r, c + 1, i + 1, board, word) || 
            dfs(r, c - 1, i + 1, board, word) || 
            dfs(r - 1, c, i + 1, board, word) || 
            dfs(r + 1, c, i + 1, board, word);
        
        board[r][c] = temp;

        return found;
    }
};