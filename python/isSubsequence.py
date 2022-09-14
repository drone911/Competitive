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

            t_ptr +=1
        if s_ptr == s_len - 1:
            print(t)
            return True
        return False
        # if t_len == 0:
        #     return False if s_len else True

assert Solution().isSubsequence("", "3") == True
assert Solution().isSubsequence("", "") == True
assert Solution().isSubsequence("3", "") == False
assert Solution().isSubsequence("3", "3") == True
assert Solution().isSubsequence("abc", "abhgdc") == True
