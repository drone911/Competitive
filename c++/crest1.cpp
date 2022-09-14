#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#include <bits/stdc++.h>
using namespace std;

ll stocks[10000001];

ll partition(ll stocks[], ll l, ll r)
{
    ll pivot = stocks[r];

    ll i = l;
    for (ll j = l; j < r; j++)
    {
        if (stocks[j] <= pivot)
        {
            swap(stocks[i], stocks[j]);
            i++;
        }
    }
    swap(stocks[i], stocks[r]);
    return i;
}
ll kSmallest(ll stocks[], ll l, ll r, ll k)
{
    if (k > 0 && k <= r - l + 1)
    {
        ll pos = partition(stocks, l, r);

        if (pos - l == k - 1)
            return stocks[pos];
        if (pos - l > k - 1)
            return kSmallest(stocks, l, pos - 1, k);

        return kSmallest(stocks, pos + 1, r, k - pos + l - 1);
    }
    else
    {
        return INT_MAX;
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    for (ll i = 0; i < N; i++)
    {
        cin >> stocks[i];
    }
    cout << kSmallest(stocks, 0, N - 1, K);
    return 0;
}