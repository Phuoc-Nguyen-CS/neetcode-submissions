class Solution {
public:
    string minWindow(string s, string t) {
       
        // We want to return the minimum window substring in which t is found in s
        // Defining the problem:
        // We need to find a way to detect unique strings & count of each letter
        // Afterwards we need to figure out the window size based on the information
        // Window size can be found from right - left + 1
        // We then keep track of what is the minimum substring
        
        if (s.empty() || t.empty()) return "";

        // Storing the frequencies of the character found in string t
        std::vector<int> charCountT(128, 0);
        for (char c : t) charCountT[c]++;

        // Find the unique characters in t
        int uniqueChars = 0;
        for (int i = 0; i < charCountT.size(); ++i) {
            if (charCountT[i] > 0) uniqueChars++;
        }

        std::vector<int> charCountS(128, 0);
        int left = 0;
        int correctChars = 0;
        int minWindow = INT_MAX;
        int startIndex = 0;
        // We can now go through the string S
        for (int right = 0; right < s.size(); ++right) {
            // Add what we found so far to charCountS
            char c = s[right];
            charCountS[c]++;

            // If we have found the correct characters
            if (charCountT[c] > 0 && charCountS[c] == charCountT[c]) {
                correctChars++;
            }

            // If we have found enough of the correctChars
            // We can handle the window now
            while (correctChars == uniqueChars) {
                if (right - left + 1 < minWindow) {
                    minWindow = right - left + 1;
                    startIndex = left;
                }

                char leftChar = s[left];
                
                if (charCountT[leftChar] > 0 && charCountS[leftChar] == charCountT[leftChar]) {
                    correctChars--;
                }

                charCountS[leftChar]--;
                left++;
            }
        }

        return (minWindow == INT_MAX) ? "" : s.substr(startIndex, minWindow);
    }
};
