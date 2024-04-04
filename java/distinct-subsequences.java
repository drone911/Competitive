class Solution {
    public int numDistinct(String s, String t) {
        int n = t.length();
        int m = s.length();
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=i; j<m; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = s.charAt(j) == t.charAt(i) ? 1 : 0;
                } else if(i==0) {
                    dp[i][j] = s.charAt(j) == t.charAt(i) ? dp[i][j-1] + 1 : dp[i][j-1];
                } else {
                    dp[i][j] = s.charAt(j) == t.charAt(i) ? dp[i][j-1] + dp[i-1][j-1] : dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
}