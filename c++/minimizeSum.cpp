#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

int main(){
    cin.tie(0);
    cout.sync_with_stdio(false);
    ll N, K, temp;
    priority_queue<ll> pq;
    cin>>N;
    cin>>K;
    for (ll i = 0; i < N; i++)
    {
        cin>>temp;
        pq.push(temp);
    }
    while (K--)
    {
        temp = pq.top();
        pq.pop();
        temp = (ll)floor(temp/2.0);
        pq.push(temp);
    }
    ll sum = 0;
    while (!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
    return 0;
}
