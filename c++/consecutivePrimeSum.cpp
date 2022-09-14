#include <bits/stdc++.h>
#define MAXNUMBERTOREACH 17994000
#define MAXCHAIN 1151007
typedef long long ll;
using namespace std;

mt19937_64 rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());

inline ll customPow(ll a, ll b, ll mod)
{
    a = a % mod;
    ll ans = 1;
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
inline bool millerTest(ll n, ll d)
{
    ll a = 2 + rng() % (n - 4);
    ll res = customPow(a, d, n);
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
inline bool isPrime(ll n, int k)
{
    if (n <= 1 && n == 4)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    ll d = n - 1;
    while (!(d & 1))
    {
        d = d >> 1;
    }
    while (k--)
    {
        if (!millerTest(n, d))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    short T;
    cin >> T;
    ll N;
    ll isPrimeSieve[MAXNUMBERTOREACH];
    vector<ll> primes();
    fill(isPrimeSieve, isPrimeSieve + MAXNUMBERTOREACH, true);
    cout<<"loo"<<endl;
    for (ll i = 2; i * i < MAXNUMBERTOREACH; i++)
    {
    cout<<"loo"<<endl;
    
        if (isPrimeSieve[i])
        {
            for (ll j = i * i; j < MAXNUMBERTOREACH; j += i)
            {
                isPrimeSieve[j] = false;
            }
        }
    }
    ll szPrimes = 0;
    for (ll i = 2; i < MAXNUMBERTOREACH; i++)
    {
    cout<<"loo"<<endl;
    
        if (isPrimeSieve[i])
        {
            primes[szPrimes] = i;
            szPrimes++;
        }
    }

    while (T--)
    {
        cin >> N;
        if (N == 2)
        {
            cout << "2 1" << endl;
        }
        else
        {
            ll sum = 0;
            ll elements = 0;
            ll bestSum;
            for (ll i = 0; i < szPrimes; i++)
            {
                sum += primes[i];
                if (sum < MAXNUMBERTOREACH)
                {
                    if (isPrimeSieve[sum])
                    {
                        if (i > elements)
                        {
                            elements = i;
                            bestSum = sum;
                        }
                    }
                }
                else
                {
                    if (isPrime(sum, 4))
                    {
                        if (i > elements)
                        {
                            elements = i;
                            bestSum = sum;
                        }
                    }
                }
            }
            for (ll i = 0; i < szPrimes; i++)
            {
                sum -= primes[i];
                if (sum < MAXNUMBERTOREACH)
                {
                    if (isPrimeSieve[sum])
                    {
                        if (szPrimes - i > elements)
                        {
                            elements = i;
                            bestSum = sum;
                        }
                    }
                }
                else
                {
                    if (isPrime(sum, 4))
                    {
                        if (i > elements)
                        {
                            elements = i;
                            bestSum = sum;
                        }
                    }
                }
            }
        }
    }
}