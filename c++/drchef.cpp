#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxPop[100002];

ll count2s(ll maxElem, ll &X)
{
    if(maxElem<=X){
        X = X*2;
        return 1;
    }else{
        ll count = 1;
        count +=ceil(log2(maxElem/(double)X));
        X = X* pow(2, count);
        return count;
    }
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, X;
        cin >> N >> X;
        for (ll i = 0; i < N; i++)
        {
            cin >> maxPop[i];
        }
        sort(maxPop, maxPop + N);
        ll totalDays = 0;
        ll skipped = 0;
        while (maxPop[skipped] < X && skipped < N)
        {
            skipped++;
        }
        
        ll i = skipped;
        while (i < N)
        {
            totalDays+= count2s(maxPop[i], X);
            i++;
        }
        totalDays += skipped;
        cout << totalDays << endl;
    }

    return 0;
}