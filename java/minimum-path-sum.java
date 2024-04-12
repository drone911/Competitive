class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];

        int i = 1;
        while(i<m) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
            i++;
        }
        int j = 1;
        while(j<n) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
            j++;
        }
        i = 1;
        while(i<m) {
            j = 1;
            while(j<n) {
                if(dp[i][j-1] < dp[i-1][j]) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } else{
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                }
                j++;
            }
            i++;
        }
        return dp[m-1][n-1];
    }
}
