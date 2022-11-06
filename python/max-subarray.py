class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        N = len(nums)
        opt = [0] * N
        opt[0] = nums[0]
        for i in range(1, N):
            opt[i] = max(nums[i], nums[i] + opt[i-1])
            
        return max(opt)
