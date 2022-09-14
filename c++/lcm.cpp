#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0){
        return b;
    }else{
        return gcd(b%a, a);
    }
}
int lcm(int a[], int n){
    int aa = a[0];
    int b = a[1];
    int lcm;
    lcm = (aa*b)/gcd(aa, b);
    for ( int i = 2; i < n; i++)
    {
        lcm = (a[i]*lcm)/gcd(a[i], lcm);
    }
    return lcm;
}

int main() {
    int a[] = {60, 36};
    int n = sizeof(a)/sizeof(int);
    cout<<gcd(60,36)<<endl;
    cout<<lcm(a, n);
}