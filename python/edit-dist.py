from pprint import pprint
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        if n == 0:
            return m
        if m==0:
            return n
        dp = [[0 for i in range(n)] for j in range(m)]
        dp[0][0] = 0 if word1[0] == word2[0] else 1
        changed = False
        for j in range(1, n):
            if word1[j] == word2[0] and not changed:
                dp[0][j] = dp[0][j-1]
                changed = True
            else:
                dp[0][j] = dp[0][j-1] + 1
        changed = False
        for i in range(1, m):
            if word2[i] == word1[0] and not changed:
                dp[i][0] = dp[i-1][0]
                changed = True
            else:
                dp[i][0] = dp[i-1][0] + 1

        for i in range(1, m):
            for j in range(1, n):
                if word2[i] == word1[j]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        # [print(dp[i]) for i in range(m)]
        return dp[m-1][n-1]
# assert Solution().minDistance("horse", "ros")
# assert Solution().minDistance("", "")  == 0
# assert Solution().minDistance("horse", "") == 5
# assert Solution().minDistance("", "dsfs") == 4

# Solution().minDistance("zoologicoarchaeologist", "zoogeologist")
Solution().minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically")