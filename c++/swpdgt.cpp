#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int a, b;
        cin>>a>>b;
        short a1, a2, b1, b2;
        a1 = a%10;
        a2 = a/10;
        b1 = b%10;
        b2 = b/10;
        cout<<a1 << " "<<a2<< " "<<b1<<" "<<b2<<endl;
        
        if(a1-b2 > 0 && a1-b2 > b1 - a2){
            short t = a1;
            a1 = b2;
            b2 = t;
        }
        else if(b1-a2>0){
            short t = a2;
            a2 = b1;
            b1 = t;
        }
        cout<<a1 + a2*10 + b1 + b2*10<<endl;
    }
    
    return 0;}