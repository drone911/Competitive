class Solution:
    def _permuteUtil(nums, result, i):
        n = len(nums)
        if i == n-1:
            return
        Solution._permuteUtil(nums, result, i+1)
        for j in range(i+1, n):
            nums[i], nums[j] = nums[j], nums[i]
            result.append(nums.copy())
            Solution._permuteUtil(nums, result, i+1)
            nums[i], nums[j] = nums[j], nums[i]

    def permute(self, nums: List[int]) -> List[List[int]]:
        result = [nums]
        Solution._permuteUtil(nums, result, 0)
        return result