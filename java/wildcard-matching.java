class Solution {
    public boolean isMatch(String s, String p) {
        int n = s.length();
        int m = p.length();

        boolean[][] dp = new boolean[m+1][n+1];
        int patternCharCount = 0;
        dp[0][0] = true;
        for(int i=1; i<=m; i++) {
            if(p.charAt(i-1) == '*') {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = false;
            }
        }
        for(int j=1; j<=n; j++) {
            dp[0][j] = false;
        }
        for(int i=1; i<=m; i++) {   
            char patternChar = p.charAt(i-1);
            if(patternChar != '*') {
                patternCharCount++;
            }
            for(int j=1; j<=n; j++) {
                int stringChar = s.charAt(j-1);
                if(patternCharCount > j) {
                    dp[i][j] = false;
                } else {
                    if(patternChar == '*') {
                        dp[i][j] = false;
                        if(dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]) {
                            dp[i][j] = true;
                        }
                    } else if(patternChar == '?') {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        if(stringChar == patternChar && dp[i-1][j-1] == true) {
                            dp[i][j] = true;
                        } else {
                            dp[i][j] = false;
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
}
