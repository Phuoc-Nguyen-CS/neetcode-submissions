class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // Lowest speed is 1 banana -> max(piles)
        int low = 1;
        int high = 0;
        int mid;
        int timeCompleted;
        int k;
        
        // Find the max
        for (int i : piles) {
            high = max(high, i); 
        }

        int ans = high;
        // Find the lowest K in which the pile of bananas can be eaten.
        while (low <= high) {
            
            mid = low + (high - low) / 2;
            k = mid;
            timeCompleted = 0;

            // See if the monkey can eat all the banana in given time
            for (int i = 0; i < piles.size(); ++i) {
                timeCompleted += (piles[i] + k - 1) / k;
            }

            // If we finished earlier
            if (timeCompleted <= h) {
                high = mid - 1;
                ans = min(ans, k);
            } else { // Did not finish
                low = mid + 1;
            }
        }

        return ans;
    }
};
