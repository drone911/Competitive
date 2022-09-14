#include <bits/stdc++.h>
typedef long long ul;
using namespace std;

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
	while (T--)
    {
        ul N;
        cin>>N;
        vector<ul> A(N);
        for (ul i = 0; i < N; i++)
        {
            cin>>A[i];
        }
        vector<ul> fromLeft(N);
        vector<ul> fromRight(N);
        ul maxLeft = 0;
        ul maxRight = 0;
        
        for (ul i = 0; i < N; i++)
        {
            maxLeft = max(maxLeft, A[i]);
            maxRight = max(maxRight, A[N-1-i]);
            fromLeft[i] = maxLeft;
            fromRight[N-1-i] = maxRight;
        }
        // for (ul i = 0; i < N; i++)
        // {
        //     cout<<fromLeft[i]<<" ";
        // }
        // for (ul i = 0; i < N; i++)
        // {
        //     cout<<fromRight[i]<<" ";
        // }
        
        ul total_water = 0;
        for (ul i = 1; i < N-1; i++)
        {
            total_water+=min(fromLeft[i-1], fromRight[i+1])>A[i]? min(fromLeft[i-1], fromRight[i+1])-A[i]: 0;
        }
        cout<<total_water<<endl;
    }
    
	return 0;
}