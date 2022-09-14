#include<bits/stdc++.h>

using namespace std;

int MIN = 0;
void calcMin(int N){
    if(N == 1){
        MIN+=2;
        return;
    }else if(N==0){
        return;
    }else{
        MIN+=N+1;
        if(N&1){
            calcMin(N/2);
            calcMin(N/2);
        }else{
            calcMin(N/2 - 1);
            calcMin(N/2);
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N, M;
        cin>>N>>M;
        int max = (N+2)*(N+1)/2 - 1;
        MIN = 0;
        calcMin(N);
        int min = MIN;
        if(M>=max){
            cout<<M-max<<"\n";
        }else if(M<min){
            cout<<"-1\n";
        }else{
            cout<<"0\n";
        }
    }

    return 0;
}