#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll fib(ll a, ll b,int n){
    ll temp;
    n-=2;
    for (int i = 0; i < n; i++)
    {
        temp = b;
        b = a;
        a = a+temp;
    }
    return a;
}

bool isPrime[1000];

int main() {
    int n1, n2;
    cin>>n1>>n2;


}