#include <bits/stdc++.h>
using namespace std;
struct Compare
{
    bool operator()(const pair<float, long> &p1, const pair<float, long> &p2)
    {
        return p1.first < p2.first;
    }
};

int main()
{
    int T;
    long N;
    long *G, *A, *B;
    cin >> T;
    while (T--)
    {
        cin >> N;
        G = new long[N];
        A = new long[N];
        B = new long[N];
        priority_queue < pair<float, long>, vector<pair<float, long>>, Compare> a;
        priority_queue < pair<float, long>, vector<pair<float, long>>, Compare> b;
        
        for (long i = 0; i < N; i++)
        {
            cin >> G[i] >> A[i] >> B[i];
            a.push(make_pair(G[i]/(float)A[i], i));
            b.push(make_pair(G[i]/(float)B[i], i));
        }
        double sum1 = 0, sum2 = 0;
        while (!a.empty() && !b.empty())
        {
            /* code */
        }
        
            auto aPop = a.top();
            auto bPop = b.top();
            
        
    }
    return 0;
}