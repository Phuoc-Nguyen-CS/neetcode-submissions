class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // Stores the Euclidean Distance + index pair
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> minHeap;

        // Maintain a minHeap of K size. The top should be K closest point to (0,0)
        for (int i = 0; i < points.size(); ++i) { 
            int x = points[i][0];
            int y = points[i][1];
            double e_distance = sqrt(x*x + y*y);
            minHeap.push({e_distance, i});
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(points[minHeap.top().second]); 
            minHeap.pop();
        }

        return res;
    }
};
