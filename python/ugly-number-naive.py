from queue import PriorityQueue


class Solution:
    def nth(self, dd: list):
        for i in range(1, 10000):
            if dd[i] == True:
                dd[i*2] = True
                dd[i*3] = True
                dd[i*5] = True

    def nthUglyNumber(self, n: int) -> int:
        dd = [False] * 100000000
        dd[1] = True
        self.nth(dd)
        # print(dd[:15])
        i = 1
        k = 1
        while True:
            if dd[k]:
                if i==n:
                    return k
                i+=1
            k+=1

Solution().nthUglyNumber(1690)
# assert Solution().nthUglyNumber(1) == 1
# assert Solution().nthUglyNumber(2) == 2
# assert Solution().nthUglyNumber(3) == 3
# assert Solution().nthUglyNumber(4) == 4
# assert Solution().nthUglyNumber(5) == 5
# assert Solution().nthUglyNumber(6) == 6
# assert Solution().nthUglyNumber(7) == 8
# assert Solution().nthUglyNumber(8) == 9
# assert Solution().nthUglyNumber(9) == 10
# assert Solution().nthUglyNumber(10) == 12
# assert Solution().nthUglyNumber(11) == 15
# assert Solution().nthUglyNumber(12) == 10
# assert Solution().nthUglyNumber(13) == 10
# assert Solution().nthUglyNumber(14) == 10
# assert Solution().nthUglyNumber(15) == 10

