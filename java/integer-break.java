class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[Math.max(4, n+1)];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i=4; i<=n; i++) {
            for(int j=1; j<=i/2; j++) {
                dp[i] = Math.max(dp[i], j * (i-j));
                dp[i] = Math.max(dp[i], dp[j] * (i-j));
                dp[i] = Math.max(dp[i], j * dp[i-j]);
            } 
        }
        return dp[n];
    }
}