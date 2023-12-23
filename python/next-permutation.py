class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n-1
        while i>0:
            if nums[i] > nums[i-1]:
                break
            i-=1
        if i == 0:
            nums.reverse()
            return
        
        i-=1
        least_small = nums[i+1]
        to_replace_index = i+1
        for j in range(i+2, n):
            if least_small >= nums[j] and nums[j] > nums[i]:
                least_small = nums[j]
                to_replace_index = j
        
        nums[i], nums[to_replace_index] =  nums[to_replace_index], nums[i]

        start = i+1 
        end = n-1
        while start<end:
            nums[start], nums[end] = nums[end], nums[start]
            start+=1
            end-=1