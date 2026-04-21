class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        // Create a hash map
        // Maps: Number to corresponding letters 
        vector<string> ans;
        string subset = "";

        unordered_map<int, string> hm = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };
        // Call DFS

        dfs(digits, ans, subset, hm,  0);

        return ans;
    }

private:
    void dfs(string& digits, vector<string>& ans, string subset, unordered_map<int, string>& hm, int i) {
        
        if (i == digits.length()) {
            if (subset != "") {
                ans.push_back(subset);
            }
            return;
        }

        string letters = hm[digits[i] - '0']; // Gives back "abc"
        for (const auto& c: letters) {
            dfs(digits, ans, subset += c, hm, i + 1);
            subset.pop_back();
        }
    }
};
