class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        std::vector<int> count(26, 0);
        for(char task : tasks) {
            count[task - 'A']++;
        }

        std::priority_queue<int> maxHeap;
        for (int i : count) {
            if (i > 0) maxHeap.push(i);
        }

        int time = 0;
        std:queue<std::pair<int,int>> q;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int count1 = maxHeap.top() - 1;
                maxHeap.pop();
                if (count1 > 0) q.push({count1, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first); q.pop();
            }
        }

        return time;
    }
};
