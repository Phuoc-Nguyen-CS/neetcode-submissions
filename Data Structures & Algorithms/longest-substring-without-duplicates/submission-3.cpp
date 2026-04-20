class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Focus on shrinking this time around
        std::unordered_set<int> seen;
        int left = 0;
        int longestSubStr = 0;
        int len = 0;

        for (int right = 0; right < s.size(); right++) {

            // We go till we find the duplicate
            // We then remove from left until we find the duplicated letter
            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);

            len = right - left + 1;
            longestSubStr = max(len, longestSubStr);
        }

        return longestSubStr;
    }
};
