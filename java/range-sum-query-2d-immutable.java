class NumMatrix {
    int n;
    int m;
    int[][] cumSum;
    public NumMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        cumSum = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(j==0) {
                    cumSum[i][0] = matrix[i][0];
                } else {
                    cumSum[i][j] = matrix[i][j] + cumSum[i][j-1];
                }
            }
        }
        for(int i=1; i<m; i++) {
            for(int j=0; j<n; j++) {
                cumSum[i][j] = cumSum[i][j] + cumSum[i-1][j];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = cumSum[row2][col2];
        int leftSum = 0, topSum = 0, intersection = 0;
        if(row1 > 0) {
            topSum = cumSum[row1-1][col2];
        }
        if(col1 > 0) {
            leftSum = cumSum[row2][col1-1];
        }
        if(row1 > 0 && col1 > 0) {
            intersection = cumSum[row1-1][col1-1];
        }
        return totalSum - leftSum - topSum + intersection;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */