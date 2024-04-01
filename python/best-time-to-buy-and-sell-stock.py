class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        mins_on_left = [prices[0]] * n
        current_min = prices[0]
        for i, price in enumerate(prices[1:]):
            mins_on_left[i+1] = current_min
            if current_min > price:
                current_min = price
        max_diff = 0
        for price, min_on_left in zip(prices[1:], mins_on_left[1:]):
            diff = price - min_on_left
            if diff > max_diff:
                max_diff = diff
        return max_diff
