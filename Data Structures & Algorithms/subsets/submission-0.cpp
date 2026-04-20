class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;
        dfs(nums, 0, subset, ans);
        return ans;
    }

private:
    void dfs(std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& ans) {
        // Base case
        if (i >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, ans);
        subset.pop_back();
        dfs(nums, i + 1, subset, ans);
    }
};
