class Solution {
    public int numTrees(int n) {
        int[] dp = new int[Math.max(4, n+1)];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            int nodes = i-1;
            for(int j=0; j<=nodes; j++) {
                int leftNodes = nodes - j;
                int rightNodes = j;                
                dp[i] += dp[leftNodes] * dp[rightNodes];
            }
        }
        return dp[n];
    }
}
