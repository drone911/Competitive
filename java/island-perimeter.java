class Solution {
    public int perimeter = 0;
    public int[][] visited;
    public final int[] directionX = new int[]{1, 0, -1, 0};
    public final int[] directionY = new int[]{0, 1, 0, -1};
    public int m;
    public int n;
    
    public void dfs(int[][] grid, int i, int j) {
        visited[i][j] = 1;
        for(int k=0; k<4; k++) {
            int nextI = i + directionX[k];
            int nextJ = j + directionY[k];
            if(nextI < 0 || nextI >= m  || nextJ < 0 || nextJ >= n) {
                perimeter++;
                continue;
            }
            if(visited[nextI][nextJ] == 0) {
                if(grid[nextI][nextJ] == 1) {
                    dfs(grid, nextI, nextJ);
                } else {
                    perimeter++;
                }
            }
        }
    }
    public int islandPerimeter(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        visited = new int[m][n];

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
}
