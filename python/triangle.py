class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        solutions = [triangle[0][0]]
        nRows = len(triangle)
        for i in range(1, nRows):
            nCols = len(triangle[i])
            nextSolutions = [None] * nCols
            nextSolutions[0] = solutions[0] + triangle[i][0]
            nextSolutions[-1] = solutions[-1] + triangle[i][-1]
            for j in range(1, nCols-1):
                current = triangle[i][j]
                nextSolutions[j] = min(solutions[j-1] + current, solutions[j] + current)
            solutions = nextSolutions
        return min(solutions)
