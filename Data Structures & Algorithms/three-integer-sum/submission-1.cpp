class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // [-4, -1, -1, 0, 1, 2]
        sort(nums.begin(), nums.end());
        
        int n = nums.size() - 1;
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    // Skipping the dupes 
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    j++, k--;
                }
                else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return result;
    }
};
