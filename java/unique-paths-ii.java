class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        int count = 0;
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        int i=1;
        while(i<m) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else{
                dp[i][0] = dp[i-1][0];
            }
            i++;
        }
        int j = 1;
        while(j<n) {
            if(obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            } else{
                dp[0][j] = dp[0][j-1];
            }
            j++;
        }
        i = 1;
        while(i<m) {
            j = 1;
            while(j<n) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                j++;
            }
            i++;
        }
        return dp[m-1][n-1];
    }
}
