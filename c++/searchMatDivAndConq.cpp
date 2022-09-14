#include <bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

void matSearch(int mat[ROW][COL], int leftRow, int rightRow, int leftCol, int rightCol, int key){
    int midRow = leftRow + (rightRow-leftRow)/2;
    int midCol = leftCol + (rightCol-leftCol)/2;
    if(mat[midRow][midCol] == key){
        cout<<key<<" found at "<<midRow<<" "<<midCol<<endl;
    }else{
        if(midRow!=rightRow || midCol != leftCol){
            matSearch(mat, leftRow, midRow, midCol, rightCol, key);
        }
        if(leftRow == rightRow && rightCol == leftCol+1){
            if(key == mat[rightRow][rightCol]){
                cout<<key<<" found at "<<midRow<<" "<<midCol<<endl;
            }
        }
        if(mat[midRow][midCol]>key){
            if(midCol-1>=leftCol){
                matSearch(mat, leftRow, rightRow, midCol-1, leftCol, key);
            }
        }else{
            if(midRow+1<=rightRow){
                matSearch(mat, midRow+1, rightRow, leftCol, rightCol, key);
            }
        }
    }
}
int main()
{
    int mat[ROW][COL] = {{10, 20, 30, 40},
                         {15, 25, 35, 45},
                         {27, 29, 37, 48},
                         {32, 33, 39, 50}};
    int key = 10;
    matSearch(mat, 0, ROW - 1, 0, COL - 1, key);
    return 0;
}
