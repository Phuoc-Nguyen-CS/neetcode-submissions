class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        
        std::string encoded_string;

        // Going through the vector
        for (const auto& str : strs) {
            // Add the delimiter + count + word
            encoded_string += std::to_string(str.length()) + "#" + str;
        } 
        return encoded_string;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> res;
        int i = 0;
        while (i < s.size()) {
            
            // Get to the delimiter
            int j = i;
            while (s[j] != '#') j++;

            // Get the length of the word 
            int length = stoi(s.substr(i, j - i));
            i = j + 1; // Go further than #

            // Get the word through the length 
            res.push_back(s.substr(i, length));
            i += length;
        }
        return res;
    }
};
