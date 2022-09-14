#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return (a.second.first * b.second.second > a.second.second * b.second.first);
}
void printOptimal(int L[], int T[], int N)
{
    vector<pair<int, pair<int, int>>> comb;
    for (int i = 0; i < N; i++)
    {
        comb.push_back(make_pair(i, make_pair(L[i], T[i])));
    }
    stable_sort(comb.begin(), comb.end(), comparator);
    for (int i = 0; i < N; i++)
    {
        cout<<comb[i].first+1<<" ";
    }
    cout<<endl;
}
int main()
{
    int L[] = {1, 2, 3, 5, 6};
    int T[] = {2, 4, 1, 3, 2};
    int N = sizeof(L) / sizeof(L[0]);
    printOptimal(L, T, N);
    return 0;
}