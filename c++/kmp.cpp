#include <bits/stdc++.h>
using namespace std;
void preprocessPattern(char pat[], int m, int lps[])
{
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void searchKMP(char str[], char pat[])
{
    int n = strlen(str);
    int m = strlen(pat);
    int lps[m];
    preprocessPattern(pat, m, lps);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (str[i] == pat[j])
        {
            i++;
            j++;
            if (j == m)
            {
                cout << "pattern matched at index:" << i << endl;
                j = lps[j - 1];
            }
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    searchKMP(txt, pat);
    return 0;
}