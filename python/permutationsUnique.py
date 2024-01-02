class Solution:
    def _permuteUniqueUtil(nums, result, i):
        n = len(nums)
        if i == n-1:
            return
        Solution._permuteUniqueUtil(nums, result, i+1)
        for j in range(i+1, n):
            nums[i], nums[j] = nums[j], nums[i]
            result.append(tuple(nums.copy()))
            Solution._permuteUniqueUtil(nums, result, i+1)
            nums[i], nums[j] = nums[j], nums[i]

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = [tuple(nums)]
        Solution._permuteUniqueUtil(nums, result, 0)
        return list(set(result))