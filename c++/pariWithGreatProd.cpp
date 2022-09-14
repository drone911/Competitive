#include <bits/stdc++.h>

using namespace std;

int findGreatest(int arr[], int n)
{
    unordered_map<int, int> isPres;

    for (int i = 0; i < n; i++)
    {
        isPres[arr[i]] += 1;
    }
    sort(arr, arr + n);
    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 0; j < i && arr[j] <= sqrt(arr[i]); j++)
        {
            if (arr[i] % arr[j] == 0)
            {
                int res = arr[i] / arr[j];
                if (arr[j] != res && isPres[res] > 0)
                {
                    return arr[i];
                }
                else if (arr[j] == res && isPres[res] > 1)
                    return arr[i];
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {17, 2, 1, 15, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findGreatest(arr, n);
    return 0;
}