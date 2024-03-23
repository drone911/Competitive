from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1]]
        for i in range(numRows-1):
            prev = result[i]
            prevLen = len(prev)

            newRes = [prev[0]]
            for j in range(0, prevLen-1):
                newRes.append(prev[j]+prev[j+1])
            newRes.append(prev[-1])

            result.append(newRes)

        return result