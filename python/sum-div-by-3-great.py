from typing import List
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, -10001, -10001]

        for num in nums:
            tmp = [None]*3
            tmp[num%3] = max(dp[num%3], dp[0] + num)
            tmp[(num+1)%3] = max(dp[(num+1)%3], dp[1] + num)
            tmp[(num+2)%3] = max(dp[(num+2)%3], dp[2] + num)
            dp = tmp
            # print(dp)
        return dp[0]


assert Solution().maxSumDivThree([1, 4, 3]) == 3
assert Solution().maxSumDivThree([1,2,3,4,4]) == 12
