class Solution:
    def dfs(self, subset, nums, ans, count):
        if count == len(nums):
            ans.append(list(subset))
            return

        subset.append(nums[count])
        self.dfs(subset, nums, ans, count + 1)
        subset.pop()
        self.dfs(subset, nums, ans, count + 1)

        return ans

    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        subset = []
        return self.dfs(subset, nums, ans, 0)
