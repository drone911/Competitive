class Solution:
    def canJump(self, nums: list[int]) -> bool:
        stack = [0]
        n = len(nums)
        visited = [False] * n
        while stack:
            i = stack.pop()
            elem = nums[i]
            if i == n-1:
                return True
            visited[i] = True
            for j in range(i+1, min(n, i+elem+1)):
                if not visited[j]:
                    stack.append(j)
        return False

print(Solution().canJump([3,2,1,0,4]))
print(Solution().canJump([3,0,8,2,0,0,1]))
print(Solution().canJump([2,3,1,1,4]))