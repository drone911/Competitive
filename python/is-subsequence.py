class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_len = len(s)
        t_len = len(t)
        if s_len == 0:
            return True
        if t_len < s_len:
            return False
        s_ptr = 0
        t_ptr = 0        
        while t_ptr < t_len:
            if s[s_ptr] == t[t_ptr]:
                s_ptr+=1
                if s_ptr == s_len:
                    return True
            t_ptr +=1
        return False
    def isSubsequence_rec(self, s: str, t: str) -> bool:
        return self.isSubsequence_rec_util(s, t, len(s)-1, len(t)-1)
    def isSubsequence_rec_util(self, s: str, t: str, m: int, n: int) -> bool:
        print(s, t, m, n)
        if m == -1:
            return True
        if n == -1:
            return False
        
        if s[m] == t[n]:
            return self.isSubsequence_rec_util(s, t, m-1, n-1)
        return self.isSubsequence_rec_util(s, t, m, n-1)
    def isSubsequence_dp(self, s: str, t: str) -> bool:
        pass
    
        
assert Solution().isSubsequence("", "3") == True
assert Solution().isSubsequence("", "") == True
assert Solution().isSubsequence("3", "") == False
assert Solution().isSubsequence("3", "34") == True
assert Solution().isSubsequence("abc", "abhgdc") == True

assert Solution().isSubsequence_rec("", "3") == True
assert Solution().isSubsequence_rec("", "") == True
assert Solution().isSubsequence_rec("3", "") == False
assert Solution().isSubsequence_rec("3", "34") == True
assert Solution().isSubsequence_rec("abc", "abchgdc") == True