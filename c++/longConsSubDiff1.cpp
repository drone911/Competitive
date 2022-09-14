#include <bits/stdc++.h>

using namespace std;

void longestSubsequence(int a[], int n)
{
    unordered_map<int, int> pres;
    pres.reserve(n);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maxLen = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pres[a[i] - 1] != 0 || pres[a[i] + 1] != 0)
        {
            if (pres[a[i] - 1] != 0 && pres[a[i] + 1] != 0)
            {
                dp[i] = dp[pres[a[i] - 1]] > dp[pres[a[i] + 1]] ? dp[pres[a[i] - 1]] + 1 : dp[pres[a[i] + 1]] + 1;
            }
            else if (pres[a[i] - 1] != 0)
            {
                dp[i] = dp[pres[a[i] - 1]] + 1;
            }
            else
            {
                dp[i] = dp[pres[a[i] + 1]] + 1;
            }
        }
        else
        {
            dp[i] = 1;
        }
        pres[a[i]] = i;
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
        }
    }
    cout << maxLen << endl;
}
int main()
{
    // -3 is temp to start array with 1
    int a[] = {-3, 1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    longestSubsequence(a, n);
    return 0;
}