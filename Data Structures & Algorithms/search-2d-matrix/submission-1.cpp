class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = (m * n) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n; // Go to the row
            int c = mid % n; // The remainder is the column

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
