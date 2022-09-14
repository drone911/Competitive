class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        dp = [0]*n
        dp[0] = 1
        primes_used = [0]*len(primes)
        for i in range(1, n):
            min_val = min([prime * dp[used] for prime, used in zip(primes, primes_used)])
            for j, prime in enumerate(primes):
                if min_val == prime*dp[primes_used[j]]:
                    primes_used[j] +=1
            dp[i] = min_val
        return dp[-1]
