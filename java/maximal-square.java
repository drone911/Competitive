class Solution {
    public int maximalSquare(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] rowSeqSum = new int[m][n];
        int[][] colSeqSum = new int[m][n];
        int[][] maxAreaDp = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(j != 0 ){                    
                    colSeqSum[i][j] = matrix[i][j] == '0' ? 0 : colSeqSum[i][j-1] + 1;
                } else{
                    colSeqSum[i][j] = matrix[i][j] == '0' ? 0 : 1;
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i != 0 ){
                    rowSeqSum[i][j] = matrix[i][j] == '0' ? 0 : rowSeqSum[i-1][j] + 1;
                } else{
                    rowSeqSum[i][j] = matrix[i][j] == '0' ? 0 : 1;
                }
            }
        }
        int maxArea = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int rowSeq = rowSeqSum[i][j];
                int colSeq = colSeqSum[i][j];                
                int minLength = Math.min(rowSeq, colSeq);
                if(minLength == 0) {
                    maxAreaDp[i][j] = 0;
                }
                else if(minLength == 1 || i ==0 || j == 0) {
                    maxAreaDp[i][j] = 1;
                } else {
                    int prevLength = (int)Math.sqrt(maxAreaDp[i-1][j-1]);
                    minLength = Math.min(minLength, prevLength + 1);
                    maxAreaDp[i][j] = minLength * minLength;
                }
                if(maxAreaDp[i][j] > maxArea) {
                    maxArea = maxAreaDp[i][j];
                }
            }
        }
        return maxArea;
    }
}