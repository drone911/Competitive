class Solution:
    def checkValid(self, numStr):
        if numStr == '0':
            return True
        if numStr[0] == '0':
            return False
        numInt = int(numStr)
        if numInt <= 255:
            return True

    def placeDots(self, start, end, dot):
        print(self.curr)
        if len(self.curr) == 3:
            sub = self.s[start:]
            if self.checkValid(sub):
                self.curr.append(sub)
                self.result.append(".".join(self.curr))
                self.curr.pop()
            return
        for i in range(end, self.n - dot + 2):
            sub = self.s[start:i]
            if not self.checkValid(sub):
                break
            self.curr.append(sub)
            self.placeDots(i, i+1, dot+1)
            self.curr.pop()
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        if n < 4:
            return []
        self.s = s
        self.n = n
        self.result = []
        self.curr = []
        self.placeDots(0, 1, 0)
        return self.result