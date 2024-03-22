class Solution:
    def canJump(self, nums: list[int]) -> bool:
        gas = 0
        for n in nums:
            if gas < 0:
                return False
            if n>gas:
                gas = n
            gas-=1
        return True

print(Solution().canJump([3,2,1,0,4]))
print(Solution().canJump([3,0,8,2,0,0,1]))
print(Solution().canJump([2,3,1,1,4]))