#include <bits/stdc++.h>
using namespace std;

bool strmatch(char txt[], char pat[], int n, int m)
{
    if (m == 0)
    {
        return n == 0;
    }
    bool dp[n + 1][m + 1];

    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        if (pat[i-1] == '*')
        {
            dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pat[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else if (pat[j - 1] == txt[i - 1] || pat[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";

    if (strmatch(str, pattern, strlen(str),
                 strlen(pattern)))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}