class TimeMap {
public:

    // Key: key 
    // Value: A vector of pairs of {timestamp, value}
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value}); 
    }
    
    string get(string key, int timestamp) {
        
        if (store.find(key) == store.end()) {
            return "";
        }

        auto& values = store[key];

        int candidate = 0;
        int left = 0;
        int right = values.size() - 1;
        string res = "";

        while (left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }

        return res;
    }
};
