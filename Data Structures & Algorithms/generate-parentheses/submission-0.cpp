class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Only add open if open < n
        // Only add closing if closing < open
        // Valid if open = closed = n
        string subset;
        vector<string> res;
        backtrack(subset, res, n, 0, 0);
        return res;
    }

private:
    void backtrack(string& subset, vector<string>& res, int n, int open, int closed) {
        
        if (n == open && n == closed) {
            res.push_back(subset);
            return;
        }
        
        if (open < n) {
            subset += "(";
            backtrack(subset, res, n, open + 1, closed);
            subset.pop_back();
        } 
        if (closed < open) {
            subset += ")";
            backtrack(subset, res, n, open, closed + 1);
            subset.pop_back();
        }
    }
};
