#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    ll N, temp;
    unordered_map<ll, ll> freqA;
    unordered_map<ll, ll> freqTot;
    ll minAll;
    cin >> T;
    while (T--)
    {
        freqA.clear();
        freqTot.clear();
        minAll = LLONG_MAX;
        cin >> N;
        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            minAll = min(minAll, temp);
            freqA[temp]++;
            freqTot[temp]++;
        }

        for (ll i = 0; i < N; i++)
        {
            cin >> temp;
            minAll = min(minAll, temp);
            freqTot[temp]++;
        }

        auto it = freqTot.begin();
        auto end = freqTot.end();
        auto endA = freqA.end();
        bool flag = false;
        vector<ll> A, B;
        unordered_map<ll, ll>::iterator itA;
        while (it != end)
        {
            if ((it->second) & 1)
            {
                flag = true;
                break;
            }
            itA = freqA.find(it->first);

            if (itA == endA)
            {
                for (int i = 0; i < it->second / 2; i++)
                {
                    B.push_back(it->first);
                }
                it++;
            }
            else
            {
                if (it->second != 2 * itA->second)
                {
                    temp = ((ll)abs(it->second - 2 * itA->second) / 2);
                    if ((it->second - 2 * itA->second) > 0)
                    {
                        for (int i = 0; i < temp; i++)
                        {
                            B.push_back(it->first);
                        }
                    }
                    else
                    {
                        for (int i = 0; i < temp; i++)
                        {
                            A.push_back(it->first);
                        }
                    }
                }
                it++;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else
        {
            if (A.size() == 0)
            {
                cout << "0" << endl;
            }
            else
            {
                sort(A.begin(), A.end());
                sort(B.begin(), B.end());

                ll finalCost = 0;
                ll i = 0;
                ll j = 0;
                ll iEnd = A.size() - 1;
                ll jEnd = B.size() - 1;
                ll maxCost = minAll * 2;
               
                while (i <= iEnd && j <= jEnd)
                {
                    if (A[i] < B[j])
                    {
                        if (A[i] < maxCost)
                        {
                            finalCost += A[i];
                        }
                        else
                        {
                            finalCost += maxCost;
                        }
                        jEnd--;
                        i++;
                    }
                    else
                    {
                        if (B[j] < maxCost)
                        {
                            finalCost += B[j];
                        }
                        else
                        {
                            finalCost += maxCost;
                        }
                        j++;
                        iEnd--;
                    }
                }

                cout << finalCost << endl;
            }
        }
    }
    return 0;
}