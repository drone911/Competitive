#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n)
{
    int maxSoFar = INT_MIN;
    int currentMax = 0;
    int start = 0;
    int end = 0;
    int currentS = 0;
    for (int i = 0; i < n; i++)
    {
        currentMax += a[i];
        if (currentMax > maxSoFar)
        {
            maxSoFar = currentMax;
            start = currentS;
            end = i;
        }
        if (currentMax < 0)
        {
            currentMax = 0;
            currentS = i + 1;
        }
        
    }
    for (int i = start; i <= end; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return maxSoFar;
}
int main()
{
    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << max_sum << endl;
    return 0;
}