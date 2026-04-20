class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        std::sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, subset, 0, 0);
        return res;
    }

private:
    void backtrack(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res, std::vector<int>& subset, int sum, int i) {
        
        // Base case
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        if (sum > target || i >= candidates.size()) {
            return;
        }

        subset.push_back(candidates[i]);
        backtrack(candidates, target, res, subset, sum + candidates[i], i + 1);
        subset.pop_back();

        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;
        backtrack(candidates, target, res, subset, sum, i + 1);
    }
};
