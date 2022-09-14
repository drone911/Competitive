#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    int T;
    long long N;
    ll temp;
    ll prev;

    cin >> T;
    while (T--)
    {
        cin >> N;
        ll sum = 0;
        cin >> prev;
        for (ll i = 0; i < N-1; i++)
        {
            cin >> temp;
            sum += abs(temp - prev) - 1;
            prev = temp;
        }
        cout << sum << endl;
    }
}