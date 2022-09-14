#include <bits/stdc++.h>

using namespace std;

int myHash(string s)
{
    int len = s.length();

    if (len == 1)
    {
        return 1;
    }
    int hash = 0;
    for (int i = 1; i < len; i++)
    {
        hash += pow(10, i - 1) * (abs(int(s[i]) - int(s[i - 1])));
    }
    return hash;
}
void groupShiftedString(string s[], int n)
{
    unordered_map<int, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[myHash(s[i])].push_back(s[i]);
    }
    for (auto it : mp)
    {
        for (auto s : it.second) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string str[] = {"acd", "dfg", "wyz", "yab", "mop",
                    "bdfh", "a", "x", "moqs"};
    int n = sizeof(str) / sizeof(str[0]);
    groupShiftedString(str, n);
    return 0;
}