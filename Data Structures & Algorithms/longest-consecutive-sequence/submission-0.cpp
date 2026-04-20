class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen;

        // Loop and input into set
        for (int i = 0; i < nums.size(); ++i) seen.insert(nums[i]);

        int longest = 0;
        for (int num : seen) {
            // If we haven't found a number before it 
            // It is a start of a sequence 
            if (seen.find(num - 1) == seen.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while(seen.find(currentNum + 1) != seen.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
