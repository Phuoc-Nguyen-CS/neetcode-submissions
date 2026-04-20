class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        std::stack<int> st;
        int maxRect = 0;
        int smallestValue = INT_MAX;

        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            int curr = heights[i];
            
            while (!st.empty() && curr < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                maxRect = max(maxRect, height * width);
            }

            st.push(i);
        }

        return maxRect;
    }
};
