#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll X[1000001];
double dist(ll X1, ll Y1, ll X2, ll Y2)
{
    return sqrt(pow(X1 - X2, 2) + pow(X2 - Y2, 2));
}

int main()
{
    ll N, K;
    ll Xn, Yn;
    double totalDistance = 0;

    for (ll i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    ll toSave = X[K - 1];

    sort(X, X + N);

    cin >> Xn >> Yn;
    if (K == N + 1)
    {
        if(Xn<=X[0] || Xn >= X[N-1]){
            if(Xn<=X[0]){
                totalDistance += dist(Xn, Yn, X[0], 0);
            }else{
                totalDistance += dist(Xn, Yn, X[N-1], 0);
            }
            for (ll i = 0; i < N-1; i++)
            {
                totalDistance+=X[i+1] - X[i];
            }
            
        }