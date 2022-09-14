#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxPop[100002];

ll count2s(ll maxElem, ll &X)
{
    if (maxElem <= X)
    {
        X = X * 2;
        return 1;
    }
    else
    {
        ll count = 1;
        count += ceil(log2(maxElem / (double)X));
        X = X * pow(2, count);
        return count;
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
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
        ll i = 0;
        while (2 * maxPop[i] <= X && i < N)
        {
            i++;
        }
        ll totalDays = i;

        while (i < N)
        {
            ll current = maxPop[i];
            if (current <= X)
            {
                X = current * 2;
                totalDays++;
            }
            else
            {
                ll count = 1;
                count += ceil(log2(current / (double)X));
                X = current*2;
                totalDays+=count;
            }
            i++;
        }
        cout<<totalDays<<endl;
    }

    return 0;
}