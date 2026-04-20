class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        backtrack(nums, res, subset, target, 0, 0);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& subset, int target, int sum, int i) {
        
        // Base case
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        // We went over repeating
        if (sum > target || i >= nums.size()) {
            return;
        }

        // We can add the same number infinite of times
        subset.push_back(nums[i]);
        backtrack(nums, res, subset, target, sum + nums[i], i);
        // If we went over we can add the future numbers
        subset.pop_back();
        backtrack(nums, res, subset, target, sum, i + 1);
    }
};
