#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> dp;
long long f(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n % 10 == 0)
    {
        return f(n / 10);
    }
    else
    {
        return n % 10;
    }
}
long long complexSum(long long p, long long q)
{
    long long res;
    for (long long i = p; i = q; i++)
    {
        if (p % 10 == 0)
        {
        }
    }
}

int main()
{
    int t;
    cin >> t;
    long long p, q;
    while (t--)
    {
        cin >> p >> q;
        cout << complexSum(p, q) << endl;
    }
    return 0;
}