#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void calcLeftCapacity(vector<double> &depths, vector<double> &leftCapacity, ll N)
{
    double sum = 0.0f;
    for (ll i = 0; i < N; i++)
    {
        leftCapacity[i] = sum;
        sum += depths[i];
    }
}
void calcRightCapacity(vector<double> &depths, vector<double> &rightCapacity, ll N)
{
    double sum = 0;
    for (ll i = N - 1; i >= 0; i--)
    {
        rightCapacity[i] = sum;
        sum += depths[i];
    }
}

void fillLeft(vector<double> &depths, ll x, ll v)
{
}
void fillRight(vector<double> &depths, ll x, ll v)
{
}

void fillWater(vector<double> &depths, ll N, ll x, ll v)
{
    x--;
    if (depths[x] == 0.0f)
    {
        return;
    }

    double toLeft, toRight;
    if (x == 0)
    {
        toLeft = 0;
        toRight = depths[x + 1];
    }
    if (x == N - 1)
    {
        toRight = 0;
        toLeft = depths[x - 1];
    }
    if (toRight >= depths[x] && toLeft >= depths[x])
    {
        double toFillLeft = v / 2.0f;
        double toFillRight = toFillLeft;
        fillRight(depths, x, toFillRight);
        fillLeft(depths, x, toFillLeft);
        if (toFillLeft != 0.0f || toFillRight != 0.0f)
        {
            if (toFillLeft != 0.0f && toFillRight != 0.0f)
            {
                for (ll i = 0; i < N; i++)
                {
                    depths[i] -= (toFillRight + toFillLeft) / N;
                }
            }
            else if (toFillLeft != 0)
            {
                fillRight(depths, x, toFillLeft);
                if (toFillLeft != 0.0)
                {
                    for (ll i = 0; i < N; i++)
                    {
                        depths[i] -= (toFillLeft) / N;
                    }
                }
            }
            else
            {
                fillLeft(depths, x, toFillRight);
                if (toFillRight != 0.0)
                {
                    for (ll i = 0; i < N; i++)
                    {
                        depths[i] -= (toFillRight) / N;
                    }
                }
            }
        }
    }
    else
    {
        double maxDepth = max(toLeft, toRight);
        if (depths[x] - v >= maxDepth)
        {
            depths[x] = depths[x] - v;
        }
        else
        {
            if (toLeft == toRight)
            {
                v -= depths[x];
                depths[x] = maxDepth;
                double toFillLeft = v / 2.0f;
                double toFillRight = toFillLeft;
                fillRight(depths, x, toFillRight);
                fillLeft(depths, x, toFillLeft);
                if (toFillLeft != 0.0f || toFillRight != 0.0f)
                {
                    if (toFillLeft != 0.0f && toFillRight != 0.0f)
                    {
                        for (ll i = 0; i < N; i++)
                        {
                            depths[i] -= (toFillRight + toFillLeft) / N;
                        }
                    }
                    else if (toFillLeft != 0)
                    {
                        fillRight(depths, x, toFillLeft);
                        if (toFillLeft != 0.0)
                        {
                            for (ll i = 0; i < N; i++)
                            {
                                depths[i] -= (toFillLeft) / N;
                            }
                        }
                    }
                    else
                    {
                        fillLeft(depths, x, toFillRight);
                        if (toFillRight != 0.0)
                        {
                            for (ll i = 0; i < N; i++)
                            {
                                depths[i] -= (toFillRight) / N;
                            }
                        }
                    }
                }
            }
            else if (toLeft > toRight)
            {
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    cout << fixed;
    int T;
    ll N, Q;
    ll temp;
    int option;
    ll x, v;
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;
        vector<double> depths;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            depths.push_back(temp);
        }
        cin >> option;
        if (option == 1)
        {
            cin >> x >> v;
            fillWater(depths, N, x, v);
        }
        else
        {
            cin >> x;
            cout << setprecision(10) << depths[x - 1] << endl;
        }
    }
}