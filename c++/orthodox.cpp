#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int bitCount(ll N, int counts[])
{
    int cnt = 0;
    int index = 0;
    while (N > 0)
    {
        if (N & 1)
        {
            cnt++;
            counts[index] += 1;
        }
        index++;
        N = N >> 1;
    }
    return cnt;
}
int main()
{
    int T;
    ll N;
    ll temp;
    cin >> T;
    while (T--)
    {
        cin >> N;
        bool flag = false;
        ll arr[N];
        if (N > 64)
        {
            flag = true;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            map<ll, int> freq;
            bool flag = false;
            ll curr;
            for (int i = 0; i < N; i++)
            {
                curr = arr[i];
                if (freq[curr] > 0)
                {
                    flag = true;
                    break;
                }
                freq[curr]++;
                for (int j = i + 1; j < N; j++)
                {
                    curr = curr | arr[j];
                 
                    if (freq[curr] > 0)
                    {
                 
                        flag = true;
                        break;
                    }

                    freq[curr]++;
                }
            }
            if (flag)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
}
