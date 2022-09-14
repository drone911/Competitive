#include<bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

void search(int mat[ROW][COL], int row, int col, int key){
    if(key>mat[row-1][col-1] || key < mat[0][0]){
        cout<<-1<<endl;
    }
    int i = row-1, j = 0;
    while (i>=0 && j<=col-1)
    {
        if(key == mat[i][j]){
            cout<<key<<" found at "<<i<<" "<<j<<endl;
        }
        if(key>mat[i][j]){
            j++;
        }else{
            i--;
        }
    }
}
int main() 
{ 
    int mat[ROW][COL] = { { 10, 20, 30, 40 }, 
                      { 15, 25, 35, 45 }, 
                      { 27, 29, 37, 48 }, 
                      { 32, 33, 39, 50 } }; 
    search(mat, ROW, COL,50); 
  
    return 0; 
}