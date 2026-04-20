class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Get the frequencies 
        std::unordered_map<int, int> counts;
        for (int num : nums) counts[num]++;

        // Create the buckets
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto const& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        // Grab the k amount 
        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};