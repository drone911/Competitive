class Solution:
    def isSafe(current, row, n):
        for i in range(row+1):
            for j in range(n):
                if current[i][j] == 'Q':
                    tempI = i-1
                    tempJ = j-1
                    while tempI >= 0 and tempJ >= 0:
                        if current[tempI][tempJ] == 'Q':
                            return False
                        tempI-=1
                        tempJ-=1
                    tempI = i+1
                    tempJ = j+1
                    while tempI <= row and tempJ < n:
                        if current[tempI][tempJ] == 'Q':
                            return False
                        tempI+=1
                        tempJ+=1
                    tempI = i-1
                    tempJ = j+1
                    while tempI >= 0 and tempJ < n:
                        if current[tempI][tempJ] == 'Q':
                            return False
                        tempI-=1
                        tempJ+=1
                    tempI = i+1
                    tempJ = j-1
                    while tempI <= row and tempJ >= 0:
                        if current[tempI][tempJ] == 'Q':
                            return False
                        tempI+=1
                        tempJ-=1
        return True

    def solveNQueensUtil(current, row, n, solutions, assigned):
        if row == n:
            solutions.append(["".join(curr) for curr in current])
            return
        for i in range(n):
            if assigned[i] == 1:
                continue
            assigned[i] = 1
            current[row][i] = 'Q'
            if Solution.isSafe(current, row, n):
                Solution.solveNQueensUtil(current, row+1, n, solutions, assigned)
            current[row][i] = '.'
            assigned[i] = 0
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        current = [None] * n
        assigned = [0] * n
        for i in range(n):
            current[i] = ['.'] * n
        row = 0
        Solution.solveNQueensUtil(current, row, n, solutions, assigned)

        return solutions