from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        i=0
        res = 0
        while i<=len(cost) - 2:
            if cost[i] <= cost[i+1]:
                res += cost[i]
                i+=1
            else:
                res += cost[i+1]
                i+=2
        return res        
assert Solution().minCostClimbingStairs([4, 1]) == 1
assert Solution().minCostClimbingStairs([100, 1, 1000, 1, 1, 100, 1]) == 4
assert Solution().minCostClimbingStairs([10,15,20]) == 15
