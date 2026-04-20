class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // Store in the max heap
        std::priority_queue<int> maxHeap;
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        if (maxHeap.size() == 0) {
            return 0;
        }

        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            
            if (y != x) {
                maxHeap.push(y - x);
            }
        }


        return maxHeap.size() == 0 ? 0 : maxHeap.top();
    }
};
