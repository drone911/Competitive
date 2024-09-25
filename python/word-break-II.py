class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.wordSet = set(wordDict)
        n = len(s)
        m = len(wordDict)
        self.s = s
        self.n = n
        self.currPath = []
        self.result = []
        self.dfs(0)
        return self.result
    
    def dfs(self, i):
        if i >= self.n:
            self.result.append(" ".join(self.currPath))
            return True
        flag = False
        for j in range(i, self.n):
            word = self.s[i:j+1]
            if word in self.wordSet:
                self.currPath.append(str(word))
                if self.dfs(j+1):
                    flag = True
                self.currPath.pop()
        return flag
