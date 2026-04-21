class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        dfs(ans, board, 0, n);

        return ans;
    }

private:

    bool isSafe(const vector<string>& board, int r, int c, int n) {
        // Check Vertical
        for (int i = 0; i < r; ++i) {
            if (board[i][c] == 'Q') return false;
        }
        // Diagonals
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >=0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // We want to use DFS to go through each cell and check if its a legal spot.
    // We go through until the number of pieces placed == N meaning we found an answer
    void dfs(vector<vector<string>>& ans, vector<string>& board, int r, int n) {

        // Base Case: We found the answer
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (isSafe(board, r, c, n)) {
                board[r][c] = 'Q';

                dfs(ans, board, r + 1, n);

                board[r][c] = '.';
            }
        }
    }
};
