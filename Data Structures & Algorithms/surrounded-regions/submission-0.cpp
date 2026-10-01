class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        // Outside board or not an O
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            board[r][c] != 'O') {
            return;
        }

        // Mark as safe
        board[r][c] = '#';

        // Explore 4 directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every border O.
        // Every O connected to the border is guaranteed to be safe.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows - 1 ||
                    j == 0 || j == cols - 1) {

                    if (board[i][j] == 'O') {
                        dfs(board, i, j);
                    }
                }
            }
        }

        // Remaining O's are surrounded.
        // '#' cells are safe O's, so restore them.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};