class Solution:
    def rle(self, n):
        result = ""
        i = 0
        l = len(n)
        while i<l:
            num = n[i]
            j = i+1
            while j<l and num == n[j]:
                j+=1
            result += f"{j-i}{num}"
            i = j
        return result

    def countAndSay(self, n: int) -> str:
        prev = "1"
        result = prev
        for i in range(2, n+1):
            result = self.rle(prev)
            prev = result
        return result
