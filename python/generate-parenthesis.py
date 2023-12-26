class Solution:
    def generateParenthesisUtil(self, current, currOpenCount, currCloseCount):
        if len(current) == self.n * 2:
            if currOpenCount == currCloseCount:
                self.results.append(current)
            return

        self.generateParenthesisUtil(current + "(",  currOpenCount+1, currCloseCount)
        if currCloseCount < currOpenCount:
            self.generateParenthesisUtil(current + ")", currOpenCount, currCloseCount + 1)

    def generateParenthesis(self, n: int) -> List[str]:
        self.results = []
        self.n = n
        current = ""
        self.generateParenthesisUtil(current, 0, 0)
        return self.results