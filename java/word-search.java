class Solution {
    public char[][] board;
    public int nRows;
    public int nCols;
    public String word;
    public int nLetters;
    public int[] directionX = {-1, 0, 1, 0};
    public int[] directionY = {0, -1, 0, 1};

    public boolean exist(char[][] board, String word) {
        this.nRows = board.length;
        this.nCols = board[0].length;
        this.nLetters = word.length();
        this.board = board;
        this.word = word;
        
        for(int i=0; i<this.nRows; i++){
            for(int j=0; j<this.nCols; j++){
                if(this.word.charAt(0) == this.board[i][j]){
                    boolean[][] isVisited = new boolean[this.nRows][this.nCols];
                    for(int k=0; k<this.nRows; k++) {
                        for(int l=0; l<this.nCols; l++) {
                            isVisited[k][l] = false;
                        }
                    }
                    if(dfs(isVisited, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public boolean dfs(boolean[][] isVisited, int depth, int x, int y) {
        isVisited[x][y] = true;
        if(depth == nLetters-1) {
            return true;
        }
        for(int i=0; i<4; i++) {
            int nextX = x + this.directionX[i];
            int nextY = y + this.directionY[i];
            if(nextX < 0 || nextX >= this.nRows || nextY < 0 || nextY >= this.nCols){
                continue;
            }
            if(!isVisited[nextX][nextY] && this.word.charAt(depth+1) == this.board[nextX][nextY]){
                if(dfs(isVisited, depth+1, nextX, nextY)){
                    return true;
                }
            }
        }
        isVisited[x][y] = false;
        return false;
    }
}