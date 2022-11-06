from typing import List
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def is_inside(guess: int):
            i = 0
            j = 1
            cnt = 0
            while j<len(nums):
                while nums[j] - nums[i] > guess:
                    i+=1
                cnt += j - i
                print(cnt)
                j+=1
            return cnt>=k
        nums.sort()
        low = 0
        high = nums[-1] - nums[0]
        while low < high:
            mid = low + (high - low)//2
            print(nums)
            print(low, mid, high)
            
            if is_inside(mid):
                high = mid
            else:
                low = mid + 1
            print(low, mid, high)
            print("sdfgfg")
        return low

Solution().smallestDistancePair([1, 1, 3, 3, 5, 5, 6], 3)