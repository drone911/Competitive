//Program for RSA asymmetric cryptographic algorithm
//for demonstration values are relatively small compared to practical application

#include <stdio.h>
#include <math.h>
typedef long long ll;
//to findfgcd
int gcd(int a, int h)
{    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}
ll power(ll x, ll y, ll mod)
{
    if (y == 0)
    {
        return 1;
    }
    ll p = power(x, y / 2, mod) % mod;
    p = (p * p) % mod;
    return (y & 1 ? (p * x) % mod : p);
}
int main()
{
    //2 random prime numbers
    ll p = 385;
    ll q = 149;
    ll n = p * q;
    ll count;
    ll totient = (p - 1) * (q - 1);

    //public key
    //e stands for encrypt
    ll e = 52277;

    //for checking co-prime which satisfies e>1
    while (e < totient)
    {
        count = gcd(e, totient);
        if (count == 1)
            break;
        else
            e++;
    }

    //private key
    //d stands for decrypt
    ll d;

    //k can be any arbitrary value
    ll k = 48065;

    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k * totient)) / e;
    ll msg = 19;
    ll c = power(msg, e, n);
    ll m = power(c, d, n);
    
    printf("Message data = %ld", msg);
    printf("\np = %ld", p);
    printf("\nq = %ld", q);
    printf("\nn = pq = %ld", n);
    printf("\ntotient = %ld", totient);
    printf("\ne = %ld", e);
    printf("\nd = %ld", d);
    printf("\nEncrypted data = %ld", c);
    printf("\nOriginal Message Sent = %ld", m);

    return 0;
}