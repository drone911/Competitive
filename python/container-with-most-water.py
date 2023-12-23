class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) -1
        max_water = 0
        while left<right:
            left_col = height[left]
            right_col = height[right]
            water = min(left_col, right_col) * (right-left)

            if water>max_water:
                max_water = water
            if left_col<right_col:
                left+=1
            else:
                right-=1

        return max_water