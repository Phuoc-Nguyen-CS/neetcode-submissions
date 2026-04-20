class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap;

        for(int num : nums) {
            maxHeap.push(num);
        }

        int count = 1;
        while(count < k) {
            maxHeap.pop();
            count += 1;
        }

        return maxHeap.top();
    }
};
