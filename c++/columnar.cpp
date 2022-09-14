#include<bits/stdc++.h>
using namespace std;

string encrypt(string text, string key){
    int M = key.length();
    int N = ceil(text.length()/M);

    int mat[M][N];
    int k = 0;
    //fill mat
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(k<text.length()){
                mat[i][j] = text[k];
                k++;
            }
        }
    }
    //getEncryptedText
    string enc = "";
    
    
}
string decrypt(string enc, string key){
    return string("d");
}
int main() {

}