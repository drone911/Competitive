from typing import List
from collections import Counter, defaultdict

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        points = defaultdict(lambda:0)
        max_number = max(nums)
        freq = Counter(nums)
        max_earnings = [0] * (max_number + 2)
        for i in range(max_number+1):
            max_earnings[i] = max(max_earnings[i-1], max_earnings[i-2] + i*freq[i])        
        
        return max_earnings[max_number]

assert Solution().deleteAndEarn([3]) == 3
assert Solution().deleteAndEarn([3, 5]) == 8
assert Solution().deleteAndEarn([1, 3]) == 4
assert Solution().deleteAndEarn([1, 2, 3]) == 4

assert Solution().deleteAndEarn([3,4,2]) == 6
assert Solution().deleteAndEarn([1,2,3]) == 4
assert Solution().deleteAndEarn([1,2,3,3]) == 7 
assert Solution().deleteAndEarn([4,2,2,3,3,3]) == 9
assert Solution().deleteAndEarn([2,2,3,3,3,4]) == 9
assert Solution().deleteAndEarn([8,7,3,8,1,4,10,10,10,2]) == 52
assert Solution().deleteAndEarn([1,2,3,4]) == 6