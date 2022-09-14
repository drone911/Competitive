#include <bits/stdc++.h>
#define d 256
using namespace std;

void search(char *pat, char *txt, int q)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    int hashPat = 0;
    int hashTxt = 0;
    for (int i = 0; i < m; i++)
    {
        hashPat = (hashPat * d + pat[i]) % q;
        hashTxt = (hashTxt * d + txt[i]) % q;
    }
    for (int i = 0; i < n - m + 1; i++)
    {
        if (hashTxt == hashPat)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (pat[j] != txt[i + j])
                {
                    break;
                }
            }
            if (j == m)
            {
                cout << "match found at:" << i << endl;
            }
        }
        else
        {
            if (i < n - m)
            {
                hashTxt = (d * (hashTxt - txt[i] * h) + txt[i + m]) % q;
                if (hashTxt < 0)
                {
                    hashTxt = hashTxt + hashPat;
                }
            }
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}