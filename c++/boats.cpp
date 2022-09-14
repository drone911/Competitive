#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.tie(0);
    cout.sync_with_stdio(false);
    int T;
    cin >> T;
    int N;
    int arr[51];
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> countWeight;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                countWeight[arr[i] + arr[j]]++;
            }
        }
        int s = INT_MIN;
        int freq = 0;
        for (auto it = countWeight.begin(); it != countWeight.end(); it++)
        {
            if (it->second > freq)
            {
                s = it->first;
                freq = it->second;
            }
        }
        freq = 0;
        unordered_map<int, int> sumMap;
        for (int i = 0; i < N; i++)
        {
            if (sumMap[s - i])
            {
                freq++;
            }
            else
            {
                sumMap[i]++;
            }
        }
        cout << freq << endl;
    }
    return 0;
}
