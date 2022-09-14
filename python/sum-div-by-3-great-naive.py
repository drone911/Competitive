from typing import List

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        return self.maxSumUtil(0, nums, 0)
    
    def maxSumUtil(self, max_sum, nums, i):
        # print(f"{'-'*i}Called with {max_sum}")
        if i == len(nums):
            if max_sum % 3 ==0:
                # print(f"Found for {max_sum}")
                return max_sum
            else:                
                # print(f"Did not found {max_sum}")
                return 0
        return max(self.maxSumUtil(max_sum+nums[i], nums, i+1), self.maxSumUtil(max_sum, nums, i+1))

assert Solution().maxSumDivThree([1, 4]) == 0