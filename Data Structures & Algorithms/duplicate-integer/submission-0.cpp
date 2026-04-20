class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> mp;

        for (const auto& c : nums) {
            // If item exists
            if (mp.find(c) != mp.end()) {
                return true;
            }
            mp[c]++;
        }
        return false;
    }
};