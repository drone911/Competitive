#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        char dir;
        char prevDir = 'J';
        int x=0, y=0;
        while(N--){
            cin>>dir;
            if(dir == prevDir){
                continue;
            }
            if(dir=='L' && prevDir != 'R'){
                x--;
            }
            if(dir=='R' && prevDir != 'L'){
                x++;
            }
            if(dir=='U' && prevDir != 'D'){
                y++;
            }
            if(dir=='D' && prevDir != 'U'){
                y--;
            }
            
            prevDir = dir;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}