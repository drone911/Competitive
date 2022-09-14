#include<bits/stdc++.h>
#define MAX 100
using namespace std;
typedef long long ll;

ll pascal[MAX+1][MAX+1];

void buildPascal(){
    for (int i = 0; i <= 100; i++)
    {
        pascal[0][i] = 1;
    }
    
    for (int i = 1; i <= 100; i++)
    {
        pascal[i][0] = 1;
        for (int j = 1; j <= 100; j++)
        {
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
        
    }
    
}
int main() {
    buildPascal();
    cout<<pascal[4][4];
}