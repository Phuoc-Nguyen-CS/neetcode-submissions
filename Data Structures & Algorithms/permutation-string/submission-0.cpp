class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        std::vector<int> targetCount (26, 0);
        std::vector<int> windowCount (26, 0);
        int left = 0;

        // Add all the frequency from s1 to an array
        for (const char c : s1) targetCount[c - 'a']++; 
        
        for (int right = 0; right < s2.size(); ++right) {
            
            windowCount[s2[right] - 'a']++;

            // We only need to increment left when we hit the length of s1
            // and remove from the current given window
            if(right >= s1.size()) {
                windowCount[s2[left] - 'a']--;
                left++;
            }

            if (targetCount == windowCount) {
                return true;
            }
        }

        return false;
    }
};
