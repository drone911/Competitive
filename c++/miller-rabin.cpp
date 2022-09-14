#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll custom_power(ll a, ll b, ll mod)
{
    ll ans = 1;
    a = a % mod;
    while (b > 0)
    {
        
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ans;
}

bool miller(ll n, ll d)
{
    ll a = 2 + rand() % (n - 4);
    ll res = custom_power(a, d, n);
    
    if (res == 1 || res == n - 1)
    {
        return true;
    }
    while (d != n - 1)
    {
        res = (res * res) % n;
        if (res == 1)
        {
            return false;
        }
        if (res == n - 1)
        {
            return true;
        }
        d = d << 1;
    }
    return false;
}
bool isPrime(ll n, int k)
{
    if (!(n & 1))
    {
        return false;
    }
    
    ll d = n - 1;
    while (d%2 == 0)
    {
        d = d>>1;
    }
    
    while (k--)
    {
        if (!miller(n, d))
        {
            return false;
        }
    }
    return true;
}
int main()
{

    cout << isPrime(15, 3) << endl;
    cout << isPrime(97, 3) << endl;
    return 0;
}