class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Maps: difference, index
        std::unordered_map<int, int> mp;

        // Go through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Get the difference
            int diff = target - nums[i];
            // If the difference exists in the mp
            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i};
            }
            // If not we add to the mp
            mp[nums[i]] = i;
        }
    }
};
