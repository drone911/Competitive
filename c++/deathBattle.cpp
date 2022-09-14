#include <bits/stdc++.h>
using namespace std;

int fact(int r){
    int fact = 1;
    while (r>0)
    {
        fact *=r;
        r--;
    }
    return fact;
}
int comb(int n, int r)
{
    if (n - r < r)
    {
        r = n - r;
    }
    int num = 1;
    int cnt = 0;
    while (cnt <= r-1)
    {
        num*=(n-cnt);
    }
    return num/fact(r);
}
int gcd(int a, int b){
    if(a==0){
        return b;
    }else{
        return gcd(b%a, a);
    }
}

int pow(int a, int b){
    if(b==0){
        return 1;
    }else{
        int pw = pow(a, b/2);
        pw = pw*pw;
        return b%2==0?pw: pw*a;
    }
}
int main()
{
    int A, H, L1, L2, M, C;
    cin >> A >> H >> L1 >> L2 >> M >> C;
    if ((A + C) * M < H)
    {
        cout << "RIP" << endl;
    }
    else if (A * M >= H)
    {
        cout << 1 << "/" << 1 << endl;
    }
    else
    {
        int minSpecial = ceil(H - A * M / (float)C);
        int P1 = comb(M, minSpecial) * pow(L1, minSpecial) * pow((L2 - L1), M - minSpecial);
        int P2 = pow(L2, M);

        for (int i = minSpecial + 1; i <= M; i++)
        {
            P1+=comb(M, i) * pow(L1, i) * pow((L2 - L1), M - i);
        }
        P1 = P1/gcd(P1, P2);
        P2 = P2/gcd(P1, P2);
        cout<<P1<<"/"<<P2<<endl;
    }
}