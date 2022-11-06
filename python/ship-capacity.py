from typing import List
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def check_if_doable(guess_capacity: int):
            loading = 0
            total_weights = len(weights)
            day = 1
            left_capacity = guess_capacity
            while day<=days and loading<total_weights:
                
                while loading<total_weights and left_capacity >=weights[loading]:
                    left_capacity -= weights[loading]
                    
                    loading+=1
                day+=1
                left_capacity = guess_capacity
            return loading >= total_weights
        # weights.sort()
        l = max(weights)
        r = sum(weights)
        while l<r:
            m = l + (r-l)//2
            if check_if_doable(m):
                r = m
            else:
                l = m + 1
            
        return l

