class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // Stores the Euclidean Distance + index pair
        std::priority_queue<std::pair<int, int>> maxHeap;

        // Maintain a minHeap of K size. The top should be K closest point to (0,0)
        for (int i = 0; i < points.size(); ++i) { 
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            maxHeap.push({distance, i});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        std::vector<std::vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return res;
    }
};
