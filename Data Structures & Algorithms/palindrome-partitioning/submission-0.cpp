class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substring;
        string key = "";
        dfs(s, ans, substring, key, 0);

        return ans;
    }

private:
    bool isPalindrome(const string& s) {
        
        // string s = accumulate(subset.begin(), subset.end(), string(""));
        if (s.empty()) return false;
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;

    }

    void dfs(string& s, vector<vector<string>>& ans, vector<string>& substring, string key, int i) {
        if (i == s.length()) {
            // If we reach the end and the current key is empty, 
            // it means the last segment was a valid palindrome and was pushed.
            if (key.empty()) {
                ans.push_back(substring);
            }
            return;
        }

        // Add current character to the running key
        key += s[i];

        // Build the string 
        dfs(s, ans, substring, key, i + 1);

        // If Palindrome, cut and start a new 
        if (isPalindrome(key)) {
            substring.push_back(key); 
            string nextKey = "";   
            dfs(s, ans, substring, nextKey, i + 1);
            substring.pop_back();     
        }
    }


};
