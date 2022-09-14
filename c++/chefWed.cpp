#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

uint F[1001];
int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    uint T, N, K, cost, currentCost, maxCost;
    unordered_map<uint, uint> seated;
    cin >> T;
    while (T--)
    {
        seated.clear();
        cin >> N >> K;
        maxCost = K;
        cost = K;
        for (uint i = 0; i < N; i++)
        {
            
            cin >> F[i];
            seated[F[i]]++;
        }
        for (auto it = seated.begin(); it != seated.end(); it++)
        {
            if(it->second>1){
                maxCost+=it->second;
            }
        }
        seated.clear();
        
        currentCost = 0;
        uint secondOcc = 0;
        uint first = -1;
        for (uint i = 0; i < N; i++)
        {
            currentCost = 0;
            seated[F[i]]++;
            if(seated[F[i]]>1 && first == -1){
                first = i;
            }
            for (auto it = seated.begin(); it != seated.end(); it++)
            {
                if(it->second>1){
                    currentCost+=it->second;
                }
            }
            if (currentCost>=K)
            {
                cost += K;
                currentCost = 0;
                seated.clear();
                i = first-1;
                first = -1;
            }
        }
        cout << min(cost + currentCost, maxCost)<< endl;
    }

    return 0;
}
