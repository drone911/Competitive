#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int compareBits(ll n1, ll n2){
    int bit1, bit2;
    int toFlip = 0;
    while (n1>0 || n2>0)
    {
        bit1 = n1%2;
        bit2 = n2%2;
        if(bit1^bit2 != 0){
            toFlip++;
        }
        n1 = n1>>1;
        n2 = n2>>1;
    }
    return toFlip;
}
int main(){
    ll n1, n2;
    cin>>n1>>n2;
    cout<<compareBits(n1, n2);
    return 0;
}