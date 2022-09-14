#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 5

bool findWord(char mat[ROW][COL], char word[], int k, int m, int i, int j)
{

    if(word[k]==mat[i][j]) {
        if(k<m) {
            if(findWord(mat, word, k+1, m, (i+1)%ROW, j)){
                cout<<word[k]<<"("<<i<<","<<j<<") ";    
            }
            if(findWord(mat, word, k+1, m, (i+1)%ROW, (j+1)%COL)){
            cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, i==0?ROW-1:i-1, j)){
            cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, (i+1)%ROW, j==0?COL-1:j-1)){
            cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, i, (j+1)%COL)){
                cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, i, j==0?COL-1:j-1)){
                cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, i==0?ROW-1:i-1, (j+1)%COL)){
                cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
            if(findWord(mat, word, k+1, m, i==0?ROW-1:i-1, j==0?COL-1:j-1)){
                cout<<word[k]<<"("<<i<<","<<j<<") ";
            }
        }else{
            cout<<word[k]<<"("<<i<<","<<j<<") ";
        }
        return true;
    }else{
        return false;
    }
}
void findWords(char mat[ROW][COL], char word[], int m)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            findWord(mat, word, 0, m, i, j);
        }
    }
}
int main()
{
    char mat[ROW][COL] = {{'B', 'N', 'E', 'Y', 'S'},
                          {'H', 'E', 'D', 'E', 'S'},
                          {'S', 'G', 'N', 'D', 'E'}};

    char word[] = "DES";

    findWords(mat, word, strlen(word) - 1);

    return 0;
}
