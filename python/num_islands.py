from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        self.visited = []
        for _ in range(self.m):
            self.visited.append([False]*self.n)
        self.grid = grid
        connected_components = 0
        for i in range(self.m):
            for j in range(self.n):
                if not self.visited[i][j] and grid[i][j] == '1':
                    to_visit = [[i, j]]
                    self.dfs(to_visit)
                    connected_components +=1
        return connected_components
    
    def dfs(self, to_visit):
        if not to_visit:
            return
        curr = to_visit.pop()
        self.visited[curr[0]][curr[1]] = True
        for (dir_x, dir_y) in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            next_i = curr[0] + dir_y
            next_j = curr[1] + dir_x
            if next_i<0 or next_i==self.m or next_j<0 or next_j==self.n or self.grid[next_i][next_j]=='0' or self.visited[next_i][next_j]:
                continue
            to_visit.append([next_i, next_j])
            self.dfs(to_visit)
print(Solution().numIslands([["0","1","0"],["1","0","1"],["0","1","0"]]))
# Solution().numIslands([["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]])