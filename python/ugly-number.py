class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [0] * n
        dp[0] = 1
        p2 = 0
        p3 = 0
        p5 = 0
        for i in range(1, n):
            res = min(2*dp[p2], 3*dp[p3], 5*dp[p5])
            if res == 2*dp[p2]:
                p2+=1
            if res == 3*dp[p3]:
                p3+=1
            if res == 5*dp[p5]:
                p5+=1
            dp[i] = res
        return dp[n-1]

assert Solution().nthUglyNumber(1) == 1
assert Solution().nthUglyNumber(2) == 2
assert Solution().nthUglyNumber(3) == 3
assert Solution().nthUglyNumber(4) == 4
assert Solution().nthUglyNumber(5) == 5
assert Solution().nthUglyNumber(6) == 6
assert Solution().nthUglyNumber(7) == 8
assert Solution().nthUglyNumber(8) == 9
assert Solution().nthUglyNumber(9) == 10
assert Solution().nthUglyNumber(10) == 12
assert Solution().nthUglyNumber(11) == 15