#include <bits/stdc++.h>
using namespace std;

int findMaxSumAbsDiff(int arr[], int n)
{

    int maxSum = INT_MIN;
    do
    {
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += abs(arr[i] - arr[i - 1]);
        }
        sum+=abs(arr[n-1] - arr[0]);
        maxSum = max(sum, maxSum);

        
    } while (next_permutation(arr, arr + n));
    return maxSum;
}
int main()
{
    int a[] = {1, 2, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);
    cout << findMaxSumAbsDiff(a, n);
}