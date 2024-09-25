class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        lps = [0] * n
        j = 0
        i = 1
        while i<n:
            if s[i] == s[j]:
                lps[i] = j + 1
                j+=1
                i+=1
            else:
                if j == 0:
                    i+=1
                else:
                    j = lps[j-1]
        return s[:lps[-1]]
