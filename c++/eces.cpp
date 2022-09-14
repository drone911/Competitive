#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 26; i++)
    {
        cout<<(char)('A'+i)<<":"<<i<<" ";
        if(i%5 == 0){
            cout<<endl;
        }
    }
    return 0;
}