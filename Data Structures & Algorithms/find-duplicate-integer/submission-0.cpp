class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // Go until slow and fast intersect 
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        int slow1 = 0;
        while (slow != slow1) {
            slow = nums[slow];
            slow1 = nums[slow1];
        }

        return slow;
    }
};
