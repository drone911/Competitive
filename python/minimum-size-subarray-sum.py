class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_size = float('inf')
        n = len(nums)
        start = 0
        end = 0
        sum = 0
        while start<n:
            while end<n:
                sum+=nums[end]
                end+=1
                if sum >= target:
                    min_size = min(min_size, end - start)
                    break
            sum-=nums[start]
            start+=1
            if sum>=target:
                min_size = min(min_size, end - start)
            while sum >= target:
                min_size = min(min_size, end - start)
                sum-=nums[start]
                start+=1

        return min_size if min_size != float('inf') else 0
    
    def minSubArrayLenAlt(self, target: int, nums: List[int]) -> int:
        min_size = float('inf')
        n = len(nums)
        sum = 0
        start = 0
        for end in range(n):
            sum+=nums[end]
            while sum >= target:
                min_size = min(min_size, end - start + 1)
                sum-=nums[start]
                start +=1

        return min_size if min_size != float('inf') else 0
        