#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }else{
        return gcd(b%a, a);
    }
}
ll extendedGcd(ll a, ll b, ll &x,ll &y){
    if(a==0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extendedGcd(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll power(ll a,ll  b,ll m){
    if(b==0){
        return 1;
    }
    ll p = power(a, b/2, m)%m;
    p = (p*p)%m;
    return b%2==0? p: a*p%m;
}
ll power(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll pow = power(a, b/2);
    pow *=pow;
    return b%2==0? pow: pow*a;
}
int main(){
    cout<<power(8, 13, 77);
    cout<<power(50, 37, 77);
    
}