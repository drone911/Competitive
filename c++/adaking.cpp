#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void getEndCoord(int K, int &xEnd, int &yEnd){
    if(K<=7){
        xEnd = 0;
        yEnd = K;
    }else{
        K-=7;
        xEnd=0;
        xEnd+=ceil(K/(float)8);
        if(xEnd>1){
            K -= (xEnd-1)*8;
            yEnd = K-1;
        }else{
            yEnd = K-1;
        }
    }
}
void fillX(int ** board, int xEnd, int yEnd){
    if(xEnd<7){
        xEnd++;
        for (int i = 0; i < 8; i++)
        {
            board[xEnd][i] = 0;
            
            if(i == yEnd){
                if(yEnd!=7){
                    board[xEnd][i+1] = 0;        
                }
                xEnd--;
            }
            
        }
    }else{
        for (int i = yEnd+1; i <8; i++)
        {
            board[xEnd][i] = 0;
        }
        
    }
}
void printBoard(int ** board){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(!board[i][j]){
                cout<<"X";
            }else if(board[i][j] == -1){
                cout<<".";
            }else{
                cout<<"O";
            }
        }
        cout<<endl;
    }
    
}
void printValidConfig(int K)
{
    int **board = new int *[8];
    for (int i = 0; i < 8; i++)
    {
        board[i] = new int[8];
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = -1;
        }
    }
    board[0][0] = 1;
    int xEnd, yEnd;
    if(K<=63){
        getEndCoord(K, xEnd, yEnd);
        fillX(board, xEnd, yEnd);
    }
    printBoard(board);
}
int main()
{
    int T;
    cin>>T;
    int K;
    while (T--)
    {
        cin>>K;
        K--;
        printValidConfig(K);
    }
}