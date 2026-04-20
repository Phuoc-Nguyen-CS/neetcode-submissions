class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                // Found the first character
                if (board[r][c] == word[0]) {
                    if (backtrack(board, word, r, c, 0)) return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int moves) {
        
        // Ensure we're in bounds
        if (r < 0 || c < 0 ||
            r >= board.size() ||
            c >= board[0].size() ||
            word[moves] != board[r][c]) {
                return false;
        }

        if (moves == word.length() - 1) return true;


        char temp = board[r][c];
        board[r][c] = '#';
        bool found = backtrack(board, word, r + 1, c, moves + 1) || // down
                        backtrack(board, word, r - 1, c, moves + 1) || // up
                        backtrack(board, word, r, c + 1, moves + 1) || // right
                        backtrack(board, word, r, c - 1, moves + 1); // left
        board[r][c] = temp;

        // backtrack(board, word, r, c + 1, moves); // Go left until we hit the border
        // backtrack(board, word, r + 1, c, moves); // Go down until we hit the border

        return found;
    }
};
