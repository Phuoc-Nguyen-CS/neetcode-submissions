class Solution {
public:
    int characterReplacement(string s, int k) {
        // Keep track of the most frequent character
        std::vector<int> charSeen(26, 0);
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;

        // The window should keep track of the window size - the most frequent letter
        // If the value is ever > k. It means more than k change has happened

        for (int right = 0; right < s.size(); ++right) {
            charSeen[s[right] - 'A']++;
            // The character found the most within the current given window
            maxFreq = max(maxFreq, charSeen[s[right] - 'A']);

            while (((right - left + 1) - maxFreq) > k) {
                charSeen[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, (right - left + 1));
        }

        return maxLen;
    }
};
