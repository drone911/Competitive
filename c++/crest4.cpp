#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll X[1000001];
double dist(ll X1, ll Y1, ll X2, ll Y2)
{
    return sqrt(pow(X1 - X2, 2) + pow(X2 - Y2, 2));
}
double distanceLeft(ll N, ll K, double minDistance, ll minIndex, ll Xn, ll Yn)
{
    double distLeft = 0;
    for (ll i = K; i >= 0; i--)
    {
        if (i == minIndex)
        {
            distLeft += minDistance;
            if (i == 1)
            {
                distLeft += dist(X[i - 1], 0, Xn, Yn);
            }
        }
        else
        {
            if (i > 0)
            {
                distLeft += X[i] - X[i - 1];
            }
        }
    }
    return distLeft;
}
double distanceRight(ll N, ll K, double minDistance, ll minIndex, ll Xn, ll Yn)
{
    double distRight = 0;
    for (ll i = K; i < N; i++)
    {
        if (i == minIndex)
        {
            distRight += minDistance;
            if (i == N - 1)
            {
                distRight += dist(X[i + 1], 0, Xn, Yn);
            }
        }
        else
        {
            if (i < N - 1)
            {
                distRight += X[i + 1] - X[i];
            }
        }
    }
    return distRight;
}

int main()
{
    ll N, K;
    ll Xn, Yn;
    double totalDistance = 0;

    for (ll i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    ll toSave = X[K - 1];

    sort(X, X + N);
    
    for (ll i = 0; i < N; i++)
    {
        if (toSave == X[i])
        {
            toSave = i;
            break;
        }
    }

    cin >> Xn >> Yn;
    if (K == N + 1)
    {
        if (dist(Xn, Yn, X[0], 0) > dist(Xn, Yn, X[N - 1], 0))
        {
            totalDistance += dist(Xn, Yn, X[N - 1], 0);
            for (ll i = N - 1; i > 0; i--)
            {
                totalDistance += X[i] - X[i - 1];
            }
        }
        else
        {
            totalDistance += dist(Xn, Yn, X[0], 0);
            for (ll i = 0; i < N - 1; i++)
            {
                totalDistance += X[i + 1] - X[i];
            }
        }
    }
    else
    {
        double minDistance = LLONG_MAX;
        ll minIndex = 0;
        for (ll i = 0; i < N; i++)
        {
            if (minDistance > dist(Xn, Yn, X[i], 0))
            {
                minDistance = dist(Xn, Yn, X[i], 0);
                minIndex = i;
            }
        }
        if (toSave == minIndex)
        {
            totalDistance += minDistance;
            if (dist(Xn, Yn, X[toSave + 1], 0) > dist(Xn, Yn, X[toSave - 1], 0))
            {
                totalDistance += dist(Xn, Yn, X[toSave - 1], 0);
            }
            else
            {
                totalDistance += dist(Xn, Yn, X[toSave + 1], 0);
            }
            ll distLeft = distanceLeft(N, toSave - 1, minDistance, minIndex, Xn, Yn);
            ll distRight = distanceRight(N, toSave + 1, minDistance, minIndex, Xn, Yn);
        }
        else
        {
            ll distLeft = distanceLeft(N, toSave, minDistance, minIndex, Xn, Yn);
            ll distRight = distanceRight(N, toSave, minDistance, minIndex, Xn, Yn);
        }
        totalDistance += distLeft;
        totalDistance += distRight;
        if (distLeft > distRight)
        {
            totalDistance += distRight;
        }
        else
        {
            totalDistance += distLeft;
        }
    }
    cout << setprecision(6) << totalDistance << endl;
    return 0;
}
