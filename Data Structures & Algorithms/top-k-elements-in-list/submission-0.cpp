class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Map storing the number, times we've seen
        std::unordered_map<int, int> mp;

        for (const auto& num : nums) {
            mp[num]++;
        }

        // Convert the mp to a vector to sort
        std::vector<std::pair<int, int>> numOfTimes;
        for (auto& it : mp) {
            numOfTimes.push_back(it);
        }

        std::sort(numOfTimes.begin(), numOfTimes.end(), [](const pair<int,int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(numOfTimes[i].first);
        }

        return result;
    }
};
