class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<int> subset;
        std::vector<std::vector<int>> res;
        std::vector<bool> used(nums.size(), false);
        backtrack(nums, subset, res, used);
        return res;
    }

private:
    void backtrack(std::vector<int> nums, std::vector<int>& subset, std::vector<std::vector<int>>& res, std::vector<bool>& used) {
        
        // Base case
        if (subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                subset.push_back(nums[i]);
                used[i] = true;
                backtrack(nums, subset, res, used);
                subset.pop_back();
                used[i] = false;
            }
        }

        
    }
};
