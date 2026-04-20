class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;

        for (int num : nums) {
            if(!seen.insert(num).second) return true;
        }
        
        return false;
    }
};