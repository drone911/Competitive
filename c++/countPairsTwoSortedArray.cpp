#include <bits/stdc++.h>
using namespace std;

int minRemove(int a[], int b[], int n, int m)
{
    unordered_map<int, int> freqA;
    unordered_map<int, int> freqB;

    int toRemove = 0;
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (i < n)
        {
            freqA[a[i]]++;
            i++;
        }
        if (j < m)
        {
            freqB[b[j]]++;
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (freqA[a[i]] != 0 && freqB[a[i]] != 0)
        {   
            toRemove += min(freqB[a[i]], freqA[a[i]]);
        }
    }
    return toRemove;
}
int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 3, 4, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << minRemove(a, b, n, m);

    return 0;
}