#include <bits/stdc++.h>
using namespace std;

struct Compare { 
    bool operator()(pair<long long, int> const& p1, pair<long long, int> const& p2) 
    { 
        if(p1.first == p2.first) {
            return p1.second > p2.second;
        }else
        {
            return p1.first<p2.first;
        }
    } 
}; 
long findMaxAnd(long *arr, long N, long K, int maxSetBit)
{
    vector<int> countBit(maxSetBit+1, 0);
    for (int i = 0; i <=maxSetBit; i++)
    {
        for (long j = 0; j < N; j++)
        {
            if(arr[j]&(long long)pow(2, i)){
                countBit[i]++;
            }
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,Compare> Q;
    for (int i = maxSetBit; i >=0; i--)
    {
        Q.push(make_pair(pow(2, i)*countBit[i], i));
    }
    long long X = 0;
    while (K>0)
    {
        auto popped = Q.top();
        Q.pop();
        X |= (long long)pow(2, popped.second);
        K--;
    }
    
    return X;
}
int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int T;
    long N, K;
    long *arr;
    cin >> T;
    while (T-- > 0)
    {
        cin >> N >> K;
        arr= new long[N];
        int maxSetBit = -1;
        for (long i = 0; i < N; i++)
        {
            cin >> arr[i];
            if ((int)(log2(arr[i])) > maxSetBit)
            {
                maxSetBit = (int)(log2(arr[i]));
            }
        }
        if(maxSetBit<K) {
            long long X=0;
            for (int i = 0; i < K; i++)
            {
                X|=(long long)pow(2, i);
            }
            cout<<X<<endl;
            continue;
        }
        cout<<findMaxAnd(arr, N, K, maxSetBit)<<endl;
    }
    return 0;
}