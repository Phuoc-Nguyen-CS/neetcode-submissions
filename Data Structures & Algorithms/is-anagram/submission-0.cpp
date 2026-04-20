class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Make sure strings are the same length
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> mp;

        // Go through the string and count the number of occurences within
        for (const auto& c : s) {
            mp[c]++;
        }

        for (const auto& c : t) {
            mp[c]--;
        }

        for (const auto& pair : mp) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
