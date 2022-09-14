#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    ll N, temp1, temp2;
    cin >> T;
    while (T--)
    {
        cin >> N;
        map<ll, int> freqA, freqB;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp1;
            freqA[temp1]++;
        }
        for (ll i = 0; i < N; i++)
        {
            cin >> temp2;
            freqB[temp2]++;
        }
        auto itA = freqA.begin();
        auto itB = freqB.begin();
        auto endA = freqA.end();
        auto endB = freqB.end();
        bool flag = false;

        while (itA != endA && itB != endB)
        {

            if (itA->first == itB->first)
            {
                if ((itA->second + itB->second) & 1)
                {
                    flag = true;
                    break;
                }
                if (itB->second == itA->second)
                {

                    freqA.erase(itA++);
                    freqB.erase(itB++);
                }
            }
            else
            {
                if (itA->second & 1 && freqB.find(itA->first)==freqB.end())
                {
                    flag = true;
                    break;
                }
                if (itB->second & 1 && freqA.find(itB->first)==freqA.end())
                {
                    flag = true;
                    break;
                }
                if (itA->first > itB->first)
                {
                    itB++;
                }
                else
                {
                    itA++;
                }
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << "A:" << endl;
            for (auto it = freqA.begin(); it != freqA.end(); it++)
            {
                cout << it->first << " " << it->second << endl;
            }

            cout << "B:" << endl;
            for (auto it = freqB.begin(); it != freqB.end(); it++)
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}