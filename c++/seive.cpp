#include <bits/stdc++.h>
#define NUMBERTOREACH10E12 17994000
#define MAX 10e7 
typedef long long ll;
using namespace std;
int main()
{
    vector<bool> isPrime(MAX, true);
    ll N;
    cin>>N;
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i*i; j <=N ; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= N; i++)
    {
        if(isPrime[i]){
            sum+=i;
            cnt++;
        }
    }
    if(sum>10e12){
        cout<<"ohh bhai limit reached"<<endl;
    }
    cout<<sum<<" "<<cnt<<endl;
}