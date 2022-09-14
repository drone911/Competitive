#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
uint v[5];
uint N, maxI, minI;
unordered_set<int> infected;
void insertInfected(int i, float infectedTime)
{
    if (infected.find(i) != infected.end())
    {
        return;
    }
    infected.insert(i);
    for (uint j = 0; j < N; j++)
    {
        if (i != j)
        {
            if (i > j && v[j] > v[i])
            {
                float crossingTime = (i - j) / (float)(v[j] - v[i]);
                if (infectedTime <= crossingTime)
                {
                    infected.insert(j);
                }
            }
            if (i < j && v[j] < v[i])
            {
                float crossingTime = (i - j) / (float)(v[j] - v[i]);
                if (infectedTime <= crossingTime)
                {
                    infected.insert(j);
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, temp;
    cin >> T;
    while (T--)
    {
        maxI = 0;
        minI = UINT_MAX;
        cin >> N;
        for (uint i = 0; i < N; i++)
        {
            cin >> v[i];
        }
        for (uint i = 0; i < N; i++)
        {
            infected.clear();
            insertInfected(i, 0.0f);
            minI = min(minI, (uint)infected.size());
            maxI = max(maxI, (uint)infected.size());
        }
        cout << minI << " " << maxI << endl;
    }

    return 0;
}
