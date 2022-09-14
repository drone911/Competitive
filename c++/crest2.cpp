#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll order[1000001];
vector<ll> ls;
int main()
{
    ll N, K;
    cin >> N >> K;
    for (ll i = 0; i < N; i++)
    {
        cin >> order[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i < K; i++)
    {
        pq.push(order[i]);
    }
    ll temp;
    for (ll i = K; i < N; i++)
    {

        temp = pq.top();
        if (temp < 0)
        {
            ls.push_back(temp);
        }
        else
        {
            ls.push_back(0);
        }
        pq.pop();

        pq.push(order[i]);
    }
    temp = pq.top();
    if (temp < 0)
    {
        ls.push_back(temp);
    }
    else
    {
        ls.push_back(0);
    }
   

    for (vector<ll>::iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}