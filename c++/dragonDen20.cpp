#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll moveRight(ll spice[], ll height[], ll start, ll end)
{
    ll sum = spice[end];
    ll curr = height[end];
    bool flag = false;
    ll i;
    for (i = end + 1; i <= start; i++)
    {
        if (curr < height[i])
        {
            curr = height[i];
            sum += spice[i];
        }
    }
    if (i == start)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}
ll moveLeft(ll spice[], ll height[], ll start, ll end)
{

    ll sum = spice[end];
    ll curr = height[end];
    bool flag = false;
    ll i;
    for (i = end - 1; i >= start; i--)
    {
        if (curr < height[i])
        {
            curr = height[i];
            sum += spice[i];
        }
    }
    if (i == start)
    {
        return sum;
    }
    else
    {
        return -1;
    }
}

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    ll height[N];
    ll spice[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> height[i];
    }
    for (ll i = 0; i < N; i++)
    {
        cin >> spice[i];
    }
    int type;
    ll start, end;
    ll pos, newSpice;
    for (ll i = 0; i < Q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> pos >> newSpice;
            spice[pos - 1] = newSpice;
        }
        else
        {
            cin >> start >> end;
            start--;
            end--;
            if (start == end)
            {
                cout << spice[start] << endl;
            }
            else if (height[start] <= height[end])
            {
                cout << -1 << endl;
            }
            else if (start > end)
            {
                cout << moveRight(spice, height, start, end) << endl;
            }
            else
            {
                cout << moveLeft(spice, height, start, end) << endl;
            }
        }
    }

    return 0;
}
