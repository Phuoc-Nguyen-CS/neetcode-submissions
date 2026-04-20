class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size()), postfix(nums.size()), result(nums.size());

        // Create the prefix 
        int leftProduct = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Create the postfix
        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0 ; --i) {
            postfix[i] = rightProduct;
            rightProduct *= nums[i];
        }

        // At Index i to create the answer we use everything prefix[i-1] and postfix[i+1]
        for (int i = 0; i < nums.size(); ++i) {
            int left  = (i == 0) ? 1 : prefix[i];
            int right = (i == nums.size() - 1) ? 1 : postfix[i];

            result[i] = left * right;
        }

        return result;
    }
};
