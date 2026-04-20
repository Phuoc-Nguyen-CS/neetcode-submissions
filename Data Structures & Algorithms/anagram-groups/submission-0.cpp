class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // We have the map
        std::unordered_map<string, std::vector<std::string>> mp;
        
        // Grab each string
        for (const auto& s : strs) {
            // Sort the string and then input it in the mp
            std::string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            mp[sortedS].push_back(s);
        }

        std::vector<std::vector<string>> result;
        
        for (const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
