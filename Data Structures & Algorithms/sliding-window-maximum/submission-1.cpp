class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        std::vector<int> result;
        std::deque<int> dq;

        // We can use the deque to keep the front() as the greatest number
        for (int right = 0; right < nums.size(); right++) {
            
            int newNumber = nums[right];

            // If new number is greater than the number before it. We pop the old number
            while (!dq.empty() && newNumber >= nums[dq.back()]) {
                dq.pop_back();
            }

            if (!dq.empty() && right - k == dq.front()) {
                dq.pop_front();
            }

            // Save the indices to calculate window size
            dq.push_back(right);
            
            // Make sure the window is valid before storing the answers
            if (right >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
