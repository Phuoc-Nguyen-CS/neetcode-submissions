class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // We can sort to skip unwanted values
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        backtrack(nums, 0, subset, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int i, vector<int>& ss, vector<vector<int>>& res) {
        
        if (i == nums.size()){
            res.push_back(ss);
            return;
        }

        ss.push_back(nums[i]);
        backtrack(nums, i + 1, ss, res);

        ss.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        backtrack(nums, i + 1, ss, res);
    }
};
