class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int target, int total, int count) {
        
        // Base case where we found something higher or equal to the target
        if (total >= target || count >= nums.size()) {
            if (total == target) {
                ans.push_back(subset);
            }
            return;
        }

        subset.push_back(nums[count]); 
        dfs(nums, ans, subset, target, total + nums[count], count);
        subset.pop_back();
        dfs(nums, ans, subset, target, total, count + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(nums, ans, subset, target, 0, 0);

        return ans;
    }
};


/**

nums = [2, 5, 6, 9]
target = 9

main:

ans = [[]]
subset = []

dfs(nums, ans, subset, target, 0, 0):
total = 2   count = 1
dfs(nums, ans, subset, target, 2, 1):
total = 7   count = 2
dfs(nums, ans, subset, target, 7, 2):
total = 13  count = 3
dfs(nums, ans, subset, target, 13, 3):
total >= 9:
count -=


**/