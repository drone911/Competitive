#include <bits/stdc++.h>
#define q 103
#define d 256

using namespace std;

void printString(char *txt, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << txt[i];
    }
}

void checkPalindromes(char *txt)
{
    int n = strlen(txt);
    cout << txt[0] << " YES" << endl;
    int hashStart = txt[0] % q, hashEnd = txt[1] % q;
    int h = 1;
    for (int i = 1; i < n; i++)
    {
        printString(txt, i);
        cout<<" ";
        if (hashStart == hashEnd)
        {
            int j;
            for (j = 0; j < i / 2; j++)
            {
                if (txt[j] != txt[i - j])
                {
                    break;
                }
            }
            if (j == i / 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
        if (i != n)
        {
            if (i & 1 == 0)
            {
                h = (h * d) % q;
                hashEnd = (d * hashEnd + txt[(i + 1)]) % q;
                hashStart = (hashStart + h * txt[(i) / 2]) % q;
            }
            else
            {
                hashEnd = (d * (hashEnd - txt[(i + 1) / 2] * h) % q + txt[i + 1] % q) % q;
            }
        }
    }
}
int main()
{
    char txt[] = "aabaacaabaa";
    checkPalindromes(txt);
    return 0;
}