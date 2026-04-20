class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> nums;

        // Loop to deal w/ row
        for (int i = 0; i < board.size(); ++i) {
            nums.clear();
            for (int j = 0; j < board.size(); ++j) {
                char current = board[i][j];
                if (current == '.') continue;
                if (!nums.insert(current).second) {
                    return false;
                }
            }
        }
        // Loop to deal w/ column 
        for (int j = 0; j < board.size(); ++j) {
            nums.clear();
            for (int i = 0; i < board.size(); ++i) {
                char current = board[i][j];
                if (current == '.') continue;
                if (!nums.insert(current).second) {
                    return false;
                }
            }
        }

        // Loop to deal w/ box
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                nums.clear();
                for (int row = 0; row < 3; row++) {
                    for (int column = 0; column < 3; column++) {
                        char current = board[i + row][j + column];
                        if (current == '.') continue;
                        if (!nums.insert(current).second) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
