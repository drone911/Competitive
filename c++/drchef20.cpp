#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxPop[100001];

ll count2s(ll maxElem, ll X){
    ll count = 0;
    while (maxElem>X)
    {
        count++;
        X= X*2;
    }
    return count+1;
}

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        ll N, X;
        cin >> N >> X;
        ll maxElem = LLONG_MIN;
        for (ll i = 0; i < N; i++)
        {
            cin >> maxPop[i];
            maxElem = max(maxPop[i], maxElem);
        }
        ll days = 0;
        ll calc;
        calc = count2s(maxElem, X);
        days += calc + N - 1;
        cout << days << endl;
    }

    return 0;
}