class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        left = 0
        right = n - 1

        while left<=right:
            mid = (left + right)//2
            if nums[mid] == target:
                start = mid
                end = mid
                while start - 1 >= 0 and nums[start-1] == target:
                    start = start-1
                while end + 1 < n and nums[end+1] == target:
                    end = end+1
                return [start, end]
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
            
        return [-1, -1]