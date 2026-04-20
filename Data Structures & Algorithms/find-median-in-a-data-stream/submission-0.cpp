class MedianFinder {
public:

    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    
    // The left side will have a maxHeap in which the biggest small number would be on top
    // The right side will have a minHeap in which the smallest big number would be on top
    // We can then get the medium through minHeap.top() + maxHeap.top() / 2
    void addNum(int num) {
        // Push into maxHeap
        maxHeap.push(num);

        // Ensure that maxHeap elements are <= minHeap elements
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }

        // Rebalancing of the sizes
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) return (minHeap.top() + maxHeap.top()) / 2.0;
        
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
    }
};
