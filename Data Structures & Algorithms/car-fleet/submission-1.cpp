class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // Sort the position while retaining the speed
        int n = position.size();
        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end());

        // Calculate the speed
        std::vector<double> turnToTarget(n, 0);
        for (int i = 0; i < n; ++i) {
            turnToTarget[i] = (double)(target - cars[i].first) / cars[i].second;
        }

        std::stack<double> st;
        for (int i = n - 1; i >= 0; --i) {
           if (st.empty() || turnToTarget[i] > st.top()) {
                st.push(turnToTarget[i]);
           }
        }

        return st.size();
    }
};
