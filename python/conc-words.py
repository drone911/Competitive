class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        self.word_set = set(words)
        self.n = len(words)
        res = []
        for i in range(0, self.n):
            dp = [None]*30
            if self.dp_util(words[i], 0, dp) is True:
                res.append(words[i])
        return res
    def dp_util(self, word, i, dp):
        if i >= len(word):
            return True
        
        if dp[i] is not None:
            return dp[i]
        
        for j in range(i, len(word)):
            print(f"{word[i:j+1]}")

            if word[i:j+1] in self.word_set and not (i==0 and j+1==len(word)):
            #if word[i:j+1] in self.word_set and (i,j+1) !=(0, len(word)):
                if self.dp_util(word, j+1, dp):
                    dp[i] = True
                    return True
        dp[i] = False
        return False

Solution().findAllConcatenatedWordsInADict(["a", "aa", "aaa"])
